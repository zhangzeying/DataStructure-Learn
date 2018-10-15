//
//  DynamicArray.h
//  CDemo
//
//  Created by zhangzey on 2018/10/14.
//  Copyright © 2018 lanmao. All rights reserved.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include <stdio.h>

//动态数组的结构体定义
typedef struct ZZYDynamicArray {
    int *pAddr; //存放数据的首地址
    int size; //当前有多个元素
    int capacity; //数组最多能容纳的元素个数
}ZZYDynamicArray;

/**
 * 初始化动态数组
 */
ZZYDynamicArray *initDynamicArray(void);
/**
 * 插入元素
 */
void insertObject(ZZYDynamicArray *array, int data);
/**
 * 根据位置删除元素
 */
void removeObjectByIndex(ZZYDynamicArray *array, int index);
/**
 * 根据值删除元素
 */
void removeObjectByValue(ZZYDynamicArray *array, int data);
/**
 * 查找元素
 */
int findObject(ZZYDynamicArray *array, int data);
/**
 * 打印数组
 */
void printDynamicArray(ZZYDynamicArray *array);
/**
 * 清空数组
 */
void removeAllObject(ZZYDynamicArray *array);
/**
 * 释放动态数组内存
 */
void freeDynamicArray(ZZYDynamicArray *array);

#endif /* DynamicArray_h */
