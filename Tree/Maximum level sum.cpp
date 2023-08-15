// https://www.interviewbit.com/problems/maximum-level-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void rec(TreeNode* root,int dep,int &ans,map<int,int>&mp){
    if(root==NULL) return;
    
    mp[dep]+=root->val;
    ans=max(ans,mp[dep]);
    rec(root->left,dep+1,ans,mp);
    rec(root->right,dep+1,ans,mp);
}
 
int Solution::solve(TreeNode* A) {
    int ans=0;
    map<int,int>mp;
    rec(A,0,ans,mp);
    return ans;
}
