//
// Created by 李宁 on 2017/11/2.
//

#ifndef ALGORITHM_FINDMINIMUMDEPTHOFBINARYTREE_H
#define ALGORITHM_FINDMINIMUMDEPTHOFBINARYTREE_H

#include <iostream>

using namespace std;

/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from root
 * node down to the nearest leaf node. Include the root node;
 */

/**
 * 在树结构中，递归太厉害了，感觉上非常难判断的地方，比如最近的节点，使用递归迎刃而解.
 * 首先，判断left right全为空的情况
 * 然后，left right至少有一个不为空，如果左子树为空，就遍历右子树；如果右子树为空，就遍历左子树；
 * 最后，left right全都不为空，都遍历，取两者较小的值
 */

struct Node
{
    int data;
    struct Node *left, *right;
};

int minDepth(const Node* root)
{
    if (root == NULL)
        return 0;

    //Base case: Leaf Node. This accounts for height = 1
    if (root->left == NULL && root->right == NULL)
        return 1;

    //If left subtree is NULL, recur for the right subtree
    if (root->left == NULL)
        return minDepth(root->right) + 1;

    // If right subtree is NULL, recur fot the right subtree
    if (root->right == NULL)
        return minDepth(root->left) + 1;

    // If left and right subtree all exist
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}


/**
 *  Test
 */
Node* createNode(int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
void test_FindMinDepthOfBinaryTree()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);

    cout << minDepth(root) << endl;
}

#endif //ALGORITHM_FINDMINIMUMDEPTHOFBINARYTREE_H
