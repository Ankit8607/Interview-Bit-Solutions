// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 
 void fun(TreeNode *root,int sum,vector<int>tmp,vector<vector<int>>&ans){
     if(root==NULL) return;
     tmp.push_back(root->val);
     if(root->left==NULL and root->right==NULL){
         if(sum==root->val) ans.push_back(tmp);
         return;
     }
     fun(root->left,sum-root->val,tmp,ans);
     fun(root->right,sum-root->val,tmp,ans);
     tmp.pop_back();
 }
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>ans;
    vector<int>tmp;
    fun(A,B,tmp,ans);
    return ans;
}
