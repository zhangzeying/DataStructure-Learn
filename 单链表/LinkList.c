//
//  LinkList.c
//  CDemo
//
//  Created by zhangzey on 2018/10/16.
//  Copyright © 2018 lanmao. All rights reserved.
//

#include "LinkList.h"
#include <stdlib.h>
#include <strings.h>

/**
 * 初始化链表
 */
LinkList *linkList_init(void) {
    LinkList *linkList = (LinkList *)malloc(sizeof(linkList));
    linkList->head = (LinkNode *)malloc(sizeof(LinkNode));
    linkList->head->data = NULL; //头结点不保存数据
    linkList->head->next = NULL;
    linkList->size = 0;
    return linkList;
}

/**
 * 按位置插入元素
 */
void linkList_insertObjectByIndex(LinkList *linkList, int index, void *data) {
    if (linkList == NULL) {
        return;
    }
    if (index < 0 || index > linkList->size) {
        printf("****** 插入失败 ******");
    }
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    LinkNode *currentNode = linkList->head;
    for (int i = 0; i < index; i++) { //拿到要插入的位置的前一个节点
        currentNode = currentNode->next;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    linkList->size++;
}

/**
 * 按位置删除元素
 */
void linkList_removeObjectByIndex(LinkList *linkList, int index) {
    if (linkList == NULL) {
        return;
    }
    if (index < 0 || index >= linkList->size) {
        printf("****** 删除失败 ******");
    }
    LinkNode *currentNode = linkList->head;
    for (int i = 0; i < index; i++) { //拿到要删除位置的前一个节点
        currentNode = currentNode->next;
    }
    LinkNode *deleteNode = currentNode->next;
    currentNode->next = deleteNode->next;
    free(deleteNode);
    linkList->size--;
}

/**
 * 查找元素
 */
int linkList_findObject(LinkList *linkList, void *data) {
    if (linkList == NULL) {
        printf("****** 查找失败 ******");
        return -1;
    }
    LinkNode *currentNode = linkList->head->next;
    int index = -1;
    for (int i = 0; i < linkList->size; i++) {
        if (currentNode->data == data) {
            index = i;
            break;
        }
        currentNode = currentNode->next;
    }
    return index;
}

/**
 * 打印链表
 */
void linkList_print(LinkList *linkList, PrintData printData) {
    if (linkList == NULL) {
        return;
    }
    LinkNode *currentNode = linkList->head->next;
    while (currentNode != NULL) {
        printData(currentNode->data);
        currentNode = currentNode->next;
    }
}

/**
 * 释放链表内存
 */
void linkList_free(LinkList *linkList) {
    if (linkList == NULL) {
        return;
    }
    LinkNode *currentNode = linkList->head;
    while (currentNode != NULL) {
        LinkNode *nextNode = currentNode->next; //存放下个节点
        free(currentNode); //释放当前节点
        currentNode = nextNode;
    }
    //释放链表
    linkList->size = 0;
    free(linkList);
}
