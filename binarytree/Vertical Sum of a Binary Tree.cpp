// https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void rec(TreeNode *root, int pos,vector<int>&arr){
     if(root==NULL) return;
     
     arr[pos]+=root->val;
     rec(root->left,pos-1,arr);
     rec(root->right,pos+1,arr);
 }
 
vector<int> Solution::verticalSum(TreeNode* A) {
    int t=2*(1e5)+10;
    vector<int>arr(t,0);
    t=1e5;
    rec(A,t,arr);
    vector<int>ans;
    for(auto i: arr){
        if(i) ans.push_back(i);
    }
    return ans;
}
