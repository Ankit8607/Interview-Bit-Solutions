// https://www.interviewbit.com/problems/preorder-traversal/

/*

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

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
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode *root=A;
    while(!st.empty() || root){
        if(root){
            ans.push_back(root->val);
            st.push(root->right);
            root=root->left;
        }
        else{
            root=st.top();
            st.pop();
        }
    }
    return ans;
}
