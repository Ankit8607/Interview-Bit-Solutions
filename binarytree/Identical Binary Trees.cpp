// https://www.interviewbit.com/problems/identical-binary-trees/

/*

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return  0 / 1  ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 
  
  */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* a, TreeNode* b) {
    if(a==NULL || b==NULL) return a==b;
    if(a->val!=b->val) return 0;
    return isSameTree(a->right,b->right)& isSameTree(a->left,b->left);
}
