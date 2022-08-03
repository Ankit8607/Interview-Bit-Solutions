// https://www.interviewbit.com/problems/recover-binary-search-tree/

/*

Two elements of a binary search tree (BST) are swapped by mistake.

Tell us the 2 values swapping which the tree will be restored.

Note:

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST         

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
 
 void fun(TreeNode *root,vector<int>&ans){
     if(root==NULL) return;
     fun(root->left,ans);
     ans.push_back(root->val);
     fun(root->right,ans);
 }
 
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int>ans;
    fun(A,ans);
    vector<int>tmp=ans;
    sort(tmp.begin(),tmp.end());
    vector<int>res;
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=tmp[i]) res.push_back(tmp[i]);
    }
    return res;
}
