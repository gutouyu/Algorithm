//
//  main.cpp
//  Algorithm
//
//  Created by 李宁 on 2017/11/1.
//  Copyright © 2017年 李宁. All rights reserved.
//

#include <iostream>
//#include "Graph/Graph.hpp"
#include "Graph/Dijkstra.h"
#include "Graph/Floyd.h"
#include "Graph/UnionFind.h"
#include "Sorting And Searching/HeapSort.h"
#include "Sorting And Searching/QuickSort.h"
#include "Sorting And Searching/BinarySearch.h"
#include "Sorting And Searching/BubbleSort.h"
#include "Tree/MinDepth.h"
#include "Tree/MaxPathSum.h"
#include "Tree/MaxPathSumLeaf2Root.h"
#include "Sorting And Searching/SearchInSortedAndRotatedArray.h"
#include "Sorting And Searching/InsertSort.h"
#include "Sorting And Searching/MergeSort.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Sorting And Searching" << endl;
//    test_QuickSort();
//    test_HeapSort();
//    test_BinarySearch();
//    test_BubbleSort();
//    test_pivotedBinarySearch();
//    test_InsertSort();
//    test_MergeSort();

    cout << "Graph" << endl;
//    test_BFS();
//    test_DFS();
//    test_dijkstra();
//    test_Floyd();
    UnionFind::test_UnionFind();

    cout << "Tree/Binary Search Tree" << endl;
//    test_FindMinDepthOfBinaryTree();
//    test_maxPathSum();
//    test_maxPathSumLeaf2Root();

    return 0;
}
