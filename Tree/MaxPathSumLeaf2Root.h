//
// Created by 李宁 on 2017/11/3.
//

#ifndef ALGORITHM_MAXPATHSUMLEAF2ROOT_H
#define ALGORITHM_MAXPATHSUMLEAF2ROOT_H
#include <iostream>
#include "TreeNode.h"
using namespace std;

int maxPathSumLeaf2Root(TreeNode* root)
{
    if (root==NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->data;

    if (root->left == NULL)
        return max(root->data, root->data + maxPathSumLeaf2Root(root->right));

    if (root->right == NULL)
        return max(root->data, root->data + maxPathSumLeaf2Root(root->left));

    int left = maxPathSumLeaf2Root(root->left);
    int right = maxPathSumLeaf2Root(root->right);
    return max(root->data, root->data + max(left, right));
}


int test_maxPathSumLeaf2Root()
{
    TreeNode *root = createNode(10);
    root->left = createNode(-2);
    root->right = createNode(7);
    root->left->left = createNode(8);
    root->left->right = createNode(-4);
    printf ("Following are the nodes on the maximum "
                    "sum path \n");
    int sum = maxPathSumLeaf2Root(root);
    printf ("\nSum of the nodes is %d ", sum);
}


#endif //ALGORITHM_MAXPATHSUMLEAF2ROOT_H
