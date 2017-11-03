//
// Created by 李宁 on 2017/11/3.
//

#ifndef ALGORITHM_INSERTSORT_H
#define ALGORITHM_INSERTSORT_H

#include <iostream>
using namespace std;

void insertSort(int arr[], int n)
{
    int i, key, j;

    // start from the second element to the last
    for (i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i-1;

        /*
         * Move elements of arr[0...i-1],
         * that are greater than key, to one
         * position ahead of their position
         */
        while (j >= 0 && arr[j] > key) //j指向要插入位置的前面
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void test_InsertSort()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertSort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

#endif //ALGORITHM_INSERTSORT_H
