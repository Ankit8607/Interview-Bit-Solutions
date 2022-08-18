// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


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
 
 TreeNode *fun(int l,int r,const vector<int>&arr){
     if(l>r) return NULL;
     
     int mid=(l+r)/2;
     TreeNode *node=new TreeNode(arr[mid]);
     node->left=fun(l,mid-1,arr);
     node->right=fun(mid+1,r,arr);
     return node;
 }
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return fun(0,A.size()-1,A);
}
