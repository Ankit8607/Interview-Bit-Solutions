// https://www.interviewbit.com/problems/cousins-in-binary-tree/

/*

Problem Description

Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.


Problem Constraints
 1 <= N <= 105 

 1 <= B <= N



Input Format
First Argument represents the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an integer array denoting the cousins of node B.

NOTE: Order doesn't matter.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [6, 7]
Output 2:

 []


Example Explanation
Explanation 1:

 Cousins of Node 5 are Node 6 and 7 so we will return [6, 7]
 Remember Node 4 is sibling of Node 5 and do not need to return this.
Explanation 2:

 Since Node 1 is the root so it doesn't have any cousin so we will return an empty array.


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
 
 int ll;
 void fun(TreeNode *root,int &tar,TreeNode *(&par),vector<int>&ans,int dep,int level){
     if(root==NULL) return;
     if((root->left and root->left->val==tar) || (root->right and root->right->val==tar)){
         par=root;
         ll=dep+1;
     }
     if(dep==level) ans.push_back(root->val);
     fun(root->left,tar,par,ans,dep+1,level);
     fun(root->right,tar,par,ans,dep+1,level);
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    TreeNode *par=NULL;
    fun(A,B,par,ans,0,-1);
    fun(A,B,par,ans,0,ll);
    sort(ans.begin(),ans.end());
    if(par->left) ans.erase(find(ans.begin(),ans.end(),par->left->val));
    if(par->right) ans.erase(find(ans.begin(),ans.end(),par->right->val));
    return ans;
}
