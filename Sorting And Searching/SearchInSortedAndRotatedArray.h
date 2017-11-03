//
// Created by 李宁 on 2017/11/3.
//

#ifndef ALGORITHM_SEARCHINSORTEDANDROTATEDARRAY_H
#define ALGORITHM_SEARCHINSORTEDANDROTATEDARRAY_H


/**
 * Give an array like 3 4 5 1 2. It is ascend but rotated.
 * Devise a way to find an element in the rotated array in O(log n) time.
 *
 * The idea is to find the pivot point, divide the array in two sub-arrays and call binary search.
 *
 * The main idea for finding pivot is – for a sorted (in increasing order) and pivoted array, pivot element is the only only element for which next element to it is smaller than it.
 * Using above criteria and binary search methodology we can get pivot element in O(logn) time
 *
 */

#include <iostream>
using namespace std;

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high) // [low, high],such as [0,n-1]
{
    // base case
    if (low > high) return -1;
    if (low == high) return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid+1])
        return mid;

    if (mid > low && arr[mid] < arr[mid-1])
        return mid-1;

    // arr[low]是一个分界点，如果arr[mid] > arr[low]说明mid处于第一部分；否则mid处于第二部分；
    if (arr[mid] >= arr[low])
        return findPivot(arr, mid+1, high);

    return findPivot(arr, low, mid-1);
}

int binarySearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, low, mid-1, key);

        return binarySearch(arr, mid+1, high, key);
    }
    return -1;
}

int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivotIdx = findPivot(arr, 0, n-1);

    // If we don't find pivot, then array is not rotated at all
    if (pivotIdx == -1)
        return binarySearch(arr, 0, n-1, key);

    if (arr[pivotIdx] == key)
        return pivotIdx;

    // arr[0]是一个分界点，前半部分都比arr[0]大，后半部分都比arr[0]小;所以根据key和arr[0]的大小比较，决定搜索范围
    if (arr[0] < key)
        return binarySearch(arr, 0, pivotIdx-1, key);

    return binarySearch(arr, pivotIdx+1, n-1, key);
}


void test_pivotedBinarySearch()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int key = 3;
    cout << pivotedBinarySearch(arr1, n, key) << endl;
}

#endif //ALGORITHM_SEARCHINSORTEDANDROTATEDARRAY_H
