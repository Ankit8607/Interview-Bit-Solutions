// https://www.interviewbit.com/problems/right-view-of-binary-tree/

/*

Problem Description

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.



Problem Constraints
1 <= Number of nodes in binary tree <= 105

0 <= node values <= 109 



Input Format
First and only argument is an pointer to the root of binary tree A.



Output Format
Return an integer array denoting the right view of the binary tree A.



Example Input
Input 1:

        1
      /   \
     2    3
    / \  / \
   4   5 6  7
  /
 8 
Input 2:

    1
   /  \
  2    3
   \
    4
     \
      5


Example Output
Output 1:

 [1, 3, 7, 8]
Output 2:

 [1, 3, 4, 5]
 
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
 
 void fun(TreeNode *root,int curdep,int &dep,vector<int>&ans){
    if(root==NULL) return;
    if(curdep>dep) ans.push_back(root->val);
    dep=max(dep,curdep);
    fun(root->right,curdep+1,dep,ans);
    fun(root->left,curdep+1,dep,ans);
 }
 
vector<int> Solution::solve(TreeNode* A) {
    vector<int>ans;
    int depth=-1;
    fun(A,0,depth,ans);
    return ans;
}
