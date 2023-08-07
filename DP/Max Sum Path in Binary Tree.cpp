// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 int rec(TreeNode* root, int &ans){
     if(root==NULL) return -1e9;
     
     int l=max(0,rec(root->left,ans));
     int r=max(0,rec(root->right,ans));
     
     ans=max(ans,root->val+l+r);
     
     return root->val+max(l,r);
 }
 
int Solution::maxPathSum(TreeNode* A) {
    int ans=-1e9;
    rec(A,ans);
    return ans;
}
