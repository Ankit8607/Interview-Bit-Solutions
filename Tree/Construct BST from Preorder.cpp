// https://www.interviewbit.com/problems/construct-bst-from-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* rec(int l,int r, vector<int> &arr, vector<int>&nxt){
    if(l>r) return NULL;
    if(l==r) return new TreeNode(arr[l]);
    
    TreeNode * head= new TreeNode(arr[l]);
    
    head->left=rec(l+1,min(r,nxt[l]-1),arr,nxt);
    head->right=rec(nxt[l],r,arr,nxt);
    
    return head;
 } 
 
TreeNode* Solution::constructBST(vector<int> &A) {
    int n=A.size();
    vector<int>nxt(n,n+10);
    stack<int>st;
    int i=0;
    while(i<n){
        while(!st.empty() and A[st.top()]<A[i]){
            nxt[st.top()]=i;
            st.pop();
        }
        st.push(i);
        i++;
    }
    return rec(0,A.size()-1,A,nxt);
}
