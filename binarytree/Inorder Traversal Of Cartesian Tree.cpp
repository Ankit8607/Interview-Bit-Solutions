// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/*

Given an inorder traversal of a cartesian tree, construct the tree.

Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
      1
      
      Given an inorder traversal of a cartesian tree, construct the tree.

Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.

Note: You may assume that duplicates do not exist in the tree.

Example :

Input : [1 2 3]

Return :   
          3
         /
        2
       /
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
 
 TreeNode *fun(int l,int r,vector<int>&arr){
     if(l>r) return NULL;
     int idx=l;
     for(int i=l+1;i<=r;i++) if(arr[i]>arr[idx]) idx=i;
     TreeNode *node=new TreeNode(arr[idx]);
     node->left=fun(l,idx-1,arr);
     node->right=fun(idx+1,r,arr);
     return node;
 }
 
TreeNode* Solution::buildTree(vector<int> &A) {
    return fun(0,A.size()-1,A);
}
