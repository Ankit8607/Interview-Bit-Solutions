// https://www.interviewbit.com/problems/inorder-traversal/

/*

Problem Description
 
 

Given a binary tree, return the inorder traversal of its nodes values.

NOTE: Using recursion is not allowed.



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the inorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [1, 3, 2]
Output 2:

 [6, 1, 3, 2]


Example Explanation
Explanation 1:

 The Inorder Traversal of the given tree is [1, 3, 2].
Explanation 2:

 The Inorder Traversal of the given tree is [6, 1, 3, 2].
 
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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    TreeNode* pCurrent = A;
    stack<TreeNode* > stack;
    
    while (!stack.empty() || pCurrent)
    {
        if (pCurrent)
        {
            stack.push(pCurrent);
            pCurrent = pCurrent->left;
        }
        else
        {
            TreeNode* pNode = stack.top();
            res.push_back(pNode->val);
            stack.pop();
            pCurrent = pNode->right;
        }
    }
    return res;
}
