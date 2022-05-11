/*

Problem Description
 
 

You are given the root of a binary tree A.
You have to find out the number of parent - child relationship whose values are consecutive numbers.



Problem Constraints
1 <= Number of nodes in the tree <= 105


Input Format
The first argument is the root of the binary tree A.


Output Format
Return a single integer denoting the number of consecutive parent - child relationships.


Example Input
Input 1:
A =  2
    / \
   1   3
Input 2:

A =  5
    / \
   1   3
      / \
     1   4


Example Output
Output 1:
2
Output 2:

1


Example Explanation
Explanation 1:
(2, 1) and (2, 3) are the consecutive parent - child relationships.
Explanation 2:

(3, 4) is the only consecutive parent - child relationship.

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
int Solution::consecutiveNodes(TreeNode* A) {
    int ans=0;
    if(A->left!=NULL){
        if((abs(A->left->val-A->val)==1)){
            ans+=1+consecutiveNodes(A->left);
        }else ans+=consecutiveNodes(A->left);
    }
    if(A->right!=NULL){
        if((abs(A->right->val-A->val)==1)){
            ans+=1+consecutiveNodes(A->right);
        }else ans+=consecutiveNodes(A->right);
    }
    return ans;
}
