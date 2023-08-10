// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode *rec(int l,int r,int node,vector<int>&a,vector<int>&b){
     if(node<0 || l>r) return NULL;
     
     TreeNode* t=new TreeNode(b[node]);
     
     int tmp;
     for(int i=r;i>=l;i--) if(b[node]==a[i]){tmp=i; break;}
     
     int len=r-tmp;
     t->right=rec(tmp+1,r,node-1,a,b);
     t->left=rec(l,tmp-1,node-len-1,a,b);
     
     return t;
 }
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return rec(0,B.size()-1,B.size()-1,A,B);
}
