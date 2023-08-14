// https://www.interviewbit.com/problems/valid-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 void rec(TreeNode *root, vector<int>& arr){
     if(root==NULL) return ;
     
     rec(root->left,arr);
     arr.push_back(root->val);
     rec(root->right,arr);
 }
 
int Solution::isValidBST(TreeNode* A) {
    vector<int>arr;
    rec(A,arr);
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>=arr[i]) return 0;
    }
    return 1;
}
