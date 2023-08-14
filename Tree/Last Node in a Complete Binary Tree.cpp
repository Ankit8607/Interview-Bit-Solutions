// https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void rec(TreeNode* root,int depth,int &dep,int &ans){
    if(root==NULL) return ;
    
    if(depth>=dep) ans=root->val,dep=depth;
    rec(root->left,depth+1,dep,ans);
    rec(root->right,depth+1,dep,ans);
}
 
int Solution::lastNode(TreeNode* A) {
    int dep=-1,ans=-1;
    rec(A,0,dep,ans);
    return ans;
}
