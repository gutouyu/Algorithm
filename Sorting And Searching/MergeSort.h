//
// Created by 李宁 on 2017/11/6.
//

#ifndef ALGORITHM_MERGESORT_H
#define ALGORITHM_MERGESORT_H

#include <iostream>
#include "../Utils.h"
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    //[low, mid], [mid+1, high]
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Copy data to temp arrays L[] and R[]
    int L[n1];
    int R[n2];
    for (int k = 0; k < n1; ++k)
    {
        L[k] = arr[low+k];
    }
    for (int k = 0; k < n2; ++k)
    {
        R[k] = arr[mid+1+k];
    }

    // 一定要注意这里的pos 是从low开始的，不是从0开始的！！！
    int i = 0, j = 0, pos = low;
    while( i < n1 && j < n2)
    {
        if (L[i] > R[j])
        {

            arr[pos++] = R[j++];

        }else{

            arr[pos++] = L[i++];

        }
    }

    while(i < n1) arr[pos++] = L[i++];
    while(j < n2) arr[pos++] = R[j++];

}

void MergeSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);

        // merge the two sorted half
        merge(arr, low, mid, high);
    }
}

void test_MergeSort()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, arr_size-1);

    printArray(arr, arr_size);
}

#endif //ALGORITHM_MERGESORT_H
