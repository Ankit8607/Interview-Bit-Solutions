// https://www.interviewbit.com/problems/level-order/

/*

Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.
 
 
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
vector<vector<int> > Solution::levelOrder(TreeNode* a) {
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    q.push(a);
    while(!q.empty()){
        int t=q.size();
        vector<int>tmp;
        while(t--){
            TreeNode* cur=q.front(); q.pop();
            tmp.push_back(cur->val);
            if(cur->left!=NULL) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        ans.push_back(tmp);
    }
    return ans;
}
