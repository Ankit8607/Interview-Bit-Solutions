// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
min depth = 2.

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
 
void fun(TreeNode *root,int dep,int &ans){
    if(root==NULL) return ;
    if(root->left==NULL and root->right==NULL){
        ans=min(ans,dep+1);
        return;
    }
    fun(root->left,dep+1,ans);
    fun(root->right,dep+1,ans);
}
int Solution::minDepth(TreeNode* A) {
    int ans=1e9;
    fun(A,0,ans);
    return ans;
}
