//
// Created by 李宁 on 2017/11/2.
// Copyright © 2017年 李宁. All rights reserved.
//

#ifndef ALGORITHM_BINARYSEARCH_H
#define ALGORITHM_BINARYSEARCH_H

#include <iostream>
#include <vector>

using namespace std;
int BinarySearch(int arr[], int low, int high, int value)
{
    if (low <= high)
    {
        int middle = (low + high) / 2;

        if (arr[middle] == value)
            return middle;

        if (arr[middle] > value)
            return BinarySearch(arr, low, middle-1,value);

        if (arr[middle] < value)
            return BinarySearch(arr, middle+1, high, value);
    }
    return -1;
}

void test_BinarySearch()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int ret = BinarySearch(arr, 0, n-1, x);
    (ret == -1) ? cout << "Element is not present in array" << endl :
                    cout << "Element is present at index " << ret << endl;
}

#endif //ALGORITHM_BINARYSEARCH_H
