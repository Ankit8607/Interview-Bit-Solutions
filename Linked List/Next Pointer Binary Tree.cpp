// https://www.interviewbit.com/problems/next-pointer-binary-tree/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*>q;
    q.push(A);
    while(!q.empty()){
        int t=q.size();
        TreeLinkNode *root=NULL;
        while(t--){
            if(root==NULL) root=q.front();
            else root->next=q.front(),root=q.front();
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        root->next=NULL;
    }
}
