// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/*

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST

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
 void fun(TreeNode *root,vector<int>&ans){
     if(root==NULL) return;
    fun(root->left,ans);
    ans.push_back(root->val);
    fun(root->right,ans);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    vector<int>ans;
    fun(A,ans);
    return ans[B-1];
}
