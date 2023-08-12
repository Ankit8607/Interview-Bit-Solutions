// https://www.interviewbit.com/problems/least-common-ancestor/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs(TreeNode *root, int depth,int parent,vector<int>&dep,vector<vector<int>>&par ){
    if(root==NULL) return ;
    
    int node=(root->val);
    dep[node]=depth;
    par[node][0]=parent;
    for(int i=1;i<20;i++){
        par[node][i]=par[par[node][i-1]][i-1];
    }
    
    dfs(root->left,depth+1,node,dep,par);
    dfs(root->right,depth+1,node,dep,par);
}
 
int lc(int a,int b,vector<vector<int>>&par,vector<int>&dep){
    if(dep[a]<dep[b]) swap(a,b);
    int jump=dep[a]-dep[b];
    for(int i=19;i>=0;i--){
        if(jump&(1<<i)){
            a=par[a][i];
        }
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--){
        if(par[a][i]!=par[b][i]){
            a=par[a][i];
            b=par[b][i];
        }
    }
    return par[a][0];
}
 
int rec(TreeNode *root){
    if(root==NULL) return 0;
    return 1+rec(root->left)+rec(root->right);
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    int n=rec(A);
    if(B>n || C>n) return -1;
    vector<vector<int>>par(n+1,vector<int>(20,0));
    vector<int>dep(n+1,-2);
    dep[0]=-1;
    dfs(A,0,0,dep,par);
    if(B==C) return B;
    return lc(B,C,par,dep);
}
