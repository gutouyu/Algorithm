#include <iostream>
#include <vector>
using namespace std;

//Heap Sort Algorithm for sorting in increasing order:


void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(vector<int>& arr, int heap_len)//取出根节点元素之后的重新调整
{
    int holeIndex = 0, value = arr[0];
    int secondChild = holeIndex * 2 + 2;

    while(secondChild < heap_len)
    {
        if( arr[secondChild] < arr[secondChild -1] )
        {
            secondChild--;//此时secondChild指向左节点
        }

        if (arr[secondChild] > arr[holeIndex])
        {
            swap(&arr[holeIndex], &arr[secondChild]);
        }

        holeIndex = secondChild;
        secondChild = 2*holeIndex + 2;
    }

    if (secondChild == heap_len)//最后没有右节点，只有左节点
    {
        secondChild--;
        if (arr[secondChild] > arr[holeIndex])
        {
            swap(&arr[secondChild], &arr[holeIndex]);
        }
    }
}

void make_heap(vector<int>& arr)
{
    //要想以一个节点为根节点来建堆，那么他的子节点必须已经满足堆的要求才行, 所以建堆过程是 bottom up
    int holeIndex = (arr.size() - 1 - 1) / 2;
    while (true)
    {
        int secondChild = 2 * holeIndex + 2;
        if (secondChild == arr.size())//如果最后只有左节点
        {
            secondChild--;
            if (arr[secondChild] > arr[holeIndex])
            {
                swap(&arr[secondChild], &arr[holeIndex]);
            }
        }
        else//左右节点都存在
        {
            if(arr[secondChild] < arr[secondChild-1])//找到最大的节点
            {
                secondChild--;
            }
            if (arr[secondChild] > arr[holeIndex])//交换根节点
            {
                swap(&arr[secondChild], &arr[holeIndex]);
            }
        }

        if (holeIndex == 0)return;//根遍历完之后退出

        holeIndex--;//继续向上遍历
    }
}

void HeapSort(vector<int>& arr)
{

    // 1. Build max heap from the input data
    make_heap(arr);

    // 3. Repeat step2 until heap size = 1
    int heap_len = arr.size();
    while(heap_len > 1)
    {
        // 2. Swap the root with the last item. Heap size - 1. Then, heapify the root of tree.
        swap(&arr[0], &arr[heap_len-1]);
        heap_len--;
        heapify(arr, heap_len);
    }
}

void printArray(const vector<int>& arr)
{
    for (auto ite : arr)
    {
        std::cout << ite << ' ';
    }
    std::cout << std::endl;
}


void test_HeapSort()
{
    vector<int> arr = {12,11,13,5,6,7};

    HeapSort(arr);

    printArray(arr);

}