// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *rec(int ind,int l,int r,vector<int>&a,vector<int>&b){
    if(ind == a.size() || l>r) return NULL;
    
    TreeNode *t=new TreeNode(a[ind]);
    int tmp;
    for(int i=l;i<=r;i++) if(a[ind]==b[i]){ tmp=i; break;}
    int left=tmp-l;
    t->left=rec(ind+1,l,tmp-1,a,b,root,head);
    t->right=rec(ind+left+1,tmp+1,r,a,b,root,head);
    return t;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    return rec(0,0,B.size()-1,A,B);
}
