// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/*

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*>q;
   vector<vector<int>>ans;
   if(root==NULL)
   {
       return ans;
   }
   q.push(root);
   int level = 0;
   while(!q.empty())
   {
       vector<int>v;
       int sz = q.size();
       while(sz--)
       {
           if(q.front()->left!=0)
           {
               q.push(q.front()->left);
           }
           if(q.front()->right!=0)
           {
               q.push(q.front()->right);
           }
           v.push_back(q.front()->val);
           q.pop();
       }
       if(level%2)
       {
           reverse(v.begin(),v.end());
       }
       ans.push_back(v);
       level++;
   }
   return ans;
}
