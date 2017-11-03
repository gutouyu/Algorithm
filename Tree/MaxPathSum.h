//
// Created by 李宁 on 2017/11/2.
//

#ifndef ALGORITHM_MAXPATHSUM_H
#define ALGORITHM_MAXPATHSUM_H

#include <iostream>

using namespace std;
/**
 * For each node there can be four ways that the max path goes through the node:
 * 1. Node only
 * 2. Max path through Left Child + Node
 * 3. Max path through Right Child + Node
 * 4. Max path through Left Child + Node + Max path through Right Child
 *
 * The idea is to keep trace of four paths and pick up the max one in the end.
 * An important thing to note is, root of every subtree need to return maximum path sum
 * such that at most one child of root is involved. This is needed for parent function call.
 * In below code, this sum is stored in ‘max_single’ and returned by the recursive function.
 */

// A binary tree node
struct TreeNode
{
    int data;
    struct TreeNode* left, *right;
};

// This function returns overall maximum path sum in 'res'
// And returns max path sum going through root.
int maxPathUtil(const TreeNode *root, int& res)
{
    //Basic case
    if (root == NULL ) return 0;

    // left and right store maximum path sum going throught left and right child of root respectively
    int left = maxPathUtil(root->left, res);
    int right = maxPathUtil(root->right, res);

    // Max path for parent call of root. This path must include at-most one child of root.
    int max_single = max(max(left,right) + root->data, root->data);//这里包含了3中情况：1，2，3

    // Max Top represents the sum when the Node under consideration is the root of the maxsum
    // path and no ancestors of root are there in max sum path.
    int max_top = max(max_single, left + right + root->data);//这里对应第4中情况

    res = max(res, max_top); //Store the Maximum Result

    return max_single;
}

int maxPathSum(const TreeNode *root)
{
    int res = INT_MIN;

    maxPathUtil(root, res);

    return res;
}

struct TreeNode* newNode(int data)
{
    TreeNode* tmp = new TreeNode();
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
};

void test_maxPathSum()
{
    struct TreeNode *root = newNode(10);
    root->left        = newNode(2);
    root->right       = newNode(10);
    root->left->left  = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left   = newNode(3);
    root->right->right->right  = newNode(4);
    std::cout << "Max path sum is " << maxPathSum(root);
}

#endif //ALGORITHM_MAXPATHSUM_H
