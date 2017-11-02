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
    int i = low - 1; //i record the last smaller number index
    int pivot = arr[high];
    for (int j = low; j <= high-1; ++j) {
        if (arr[j] <= pivot)
        {
            i++;
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
        }
    }
    
    i++;
    arr[high] = arr[i];
    arr[i] = pivot;
    
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


int test_quick_search(int argc, const char * argv[]) {
        int number_test, numbers;
        cin >> number_test;
    
        while (number_test--)
        {
            cin >> numbers;
            vector<int> arr;
            while (numbers--)
            {
                int tmp; cin >> tmp;
                arr.push_back(tmp);
            }
            //quick sort
            QuickSort(arr, 0, arr.size() - 1);
    
            //print
            for (vector<int>::iterator ite = arr.begin(); ite != arr.end(); ++ite)
            {
                cout << *ite << " ";
            }
            cout << endl;
    
        }
    return 0;
}
