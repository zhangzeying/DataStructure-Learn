//
//  DynamicArray.c
//  CDemo
//
//  Created by zhangzey on 2018/10/14.
//  Copyright © 2018 lanmao. All rights reserved.
//

#include "DynamicArray.h"
#include <stdlib.h>
#include <strings.h>

/**
 * 初始化动态数组
 */
ZZYDynamicArray *initDynamicArray(void) {
    ZZYDynamicArray *array = (ZZYDynamicArray *)malloc(sizeof(ZZYDynamicArray));
    array->size = 0;
    array->capacity = 20;
    array->pAddr = (int *)malloc(sizeof(int) * array->capacity);
    return array;
}

/**
 * 插入元素
 */
void insertObject(ZZYDynamicArray *array, int data) {
    if (array == NULL) {
        return;
    }
    if (array->size == array->capacity) {
        int *newSpace = (int *)malloc(sizeof(int) * array->capacity * 2);
        memcpy(newSpace, array->pAddr, sizeof(int) * array->capacity);
        free(array->pAddr);
        array->capacity = array->capacity * 2;
        array->pAddr = newSpace;
    }
    array->pAddr[array->size] = data;
    array->size++;
}

/**
 * 根据位置删除元素
 */
void removeObjectByIndex(ZZYDynamicArray *array, int index) {
    if (array == NULL) {
        return;
    }
    if (index < 0 || index >= array->size) {
        return;
    }
    //删除元素
    for (int i = index; i < array->size - 1; i++) {
        array->pAddr[i] = array->pAddr[i + 1];
    }
    array->size--;
}

/**
 * 根据值删除元素
 */
void removeObjectByValue(ZZYDynamicArray *array, int data) {
    if (array == NULL) {
        return;
    }
    int index = findObject(array, data);
    removeObjectByIndex(array, index);
}

/**
 * 查找元素
 */
int findObject(ZZYDynamicArray *array, int data) {
    if (array == NULL) {
        return -1;
    }
    int index = -1;
    for (int i = 0; i < array->size; i++) {
        if (array->pAddr[i] == data) {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * 打印数组
 */
void printDynamicArray(ZZYDynamicArray *array) {
    if (array == NULL) {
        return;
    }
    for (int i = 0; i < array->size; i++) {
        printf("%d\n", array->pAddr[i]);
    }
}

/**
 * 清空数组
 */
void removeAllObject(ZZYDynamicArray *array) {
    if (array == NULL) {
        return;
    }
    array->size = 0;
}

/**
 * 释放动态数组内存
 */
void freeDynamicArray(ZZYDynamicArray *array) {
    if (array == NULL) {
        return;
    }
    if (array->pAddr != NULL) {
        free(array->pAddr);
    }
    free(array);
}
