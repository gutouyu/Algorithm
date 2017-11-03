//
//  main.cpp
//  Algorithm
//
//  Created by 李宁 on 2017/11/1.
//  Copyright © 2017年 李宁. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1; //i record the last smaller number index

    for (int j = low; j <= high-1; ++j) {

        if (arr[j] <= pivot) //利用j的遍历，来找到合适的，也就是比pivot小的，放到i后面的位置
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    i++;
    swap(arr[i], arr[high]);

    return i;
}

void QuickSort(vector<int>& arr, int low, int high)
{
    if (low < high )
    {
        int pi = partition(arr, low, high);

        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}


int test_QuickSort()
{
    int arr[] = {11, 15, 13, 10, 4, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> iarr(arr, arr+n);

    QuickSort(iarr, 0, n - 1);

    for (auto ite : iarr)
    {
        cout << ite << " ";
    }
    cout << endl;
    return 0;
}
