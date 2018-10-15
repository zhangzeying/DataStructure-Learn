//
//  main.c
//  CDemo
//
//  Created by zhangzey on 10/09/2018.
//  Copyright © 2018 lanmao. All rights reserved.
//

#include <stdio.h>
#include "DynamicArray.h"

void testDynamicArray() {
    ZZYDynamicArray *array = initDynamicArray();
    for (int i = 0; i < 10; i++) {
        insertObject(array, i);
    }
    removeObjectByIndex(array, 2);
    printDynamicArray(array);
    printf("%d\n", findObject(array, 6));
    removeAllObject(array);
    printDynamicArray(array);
    freeDynamicArray(array);
}

int main(int argc, const char * argv[]) {
    testDynamicArray();
    return 0;
}


