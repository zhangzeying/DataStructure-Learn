//
//  LinkList.h
//  CDemo
//
//  Created by zhangzey on 2018/10/16.
//  Copyright © 2018 lanmao. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

//链表节点结构体
typedef struct LinkNode {
    void *data;
    struct LinkNode *next;
    
}LinkNode;

//链表结构体
typedef struct LinkList {
    LinkNode *head;
    int size;
    
}LinkList;

//定义一个回调函数
typedef void(*PrintData)(void *);

/**
 * 初始化链表
 */
LinkList *linkList_init(void);

/**
 * 按位置插入元素
 */
void linkList_insertObjectByIndex(LinkList *linkList, int index, void *data);

/**
 * 按位置删除元素
 */
void linkList_removeObjectByIndex(LinkList *linkList, int index);

/**
 * 查找元素
 */
int linkList_findObject(LinkList *linkList, void *data);

/**
 * 打印链表
 */
void linkList_print(LinkList *linkList, PrintData printData);

/**
 * 释放链表内存
 */
void linkList_free(LinkList *linkList);

#endif /* LinkList_h */
