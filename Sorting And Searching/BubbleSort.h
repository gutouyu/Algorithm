//
// Created by 李宁 on 2017/11/2.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

#include <iostream>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int arr[], int n)
{

    for (int i = 0; i <= n - 2; ++i)//因为前面至少要有两个元素来进行比较，所以i <= n - 2
    {
        bool swaped = false;
        // Last i elements are already in place, 随意还剩下 n - i 个元素，所以 j < n - i
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j+1])//因为之前设置i的时候，就保证了至少有给前面留下2个元素，所以不用再判断j+1
            {
                swap(&arr[j], &arr[j+1]);
                swaped = true;
            }
        }

        if(swaped == false) return;//如果整次下来都没有发生过交换，说明已经排好序了，提前结束
    }
}

void test_BubbleSort()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif //ALGORITHM_BUBBLESORT_H
