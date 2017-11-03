//
// Created by 李宁 on 2017/11/3.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H

#include <MacTypes.h>

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data)
{
    TreeNode *tmp = new TreeNode();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

#endif //ALGORITHM_TREENODE_H
