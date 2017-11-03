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
#include "Sorting And Searching/HeapSort.h"
#include "Sorting And Searching/BinarySearch.h"
#include "Sorting And Searching/BubbleSort.h"
#include "Tree/MinDepth.h"
#include "Tree/MaxPathSum.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Sorting And Searching" << endl;
//    test_HeapSort();
//    test_BinarySearch();
//    test_BubbleSort();


    cout << "Graph" << endl;
//    test_BFS();
//    test_DFS();
//    test_dijkstra();

    cout << "Tree/Binary Search Tree" << endl;
//    test_FindMinDepthOfBinaryTree();
    test_maxPathSum();

    return 0;
}
