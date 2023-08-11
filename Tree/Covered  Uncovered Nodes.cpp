// https://www.interviewbit.com/problems/covered-uncovered-nodes/

long Solution::coveredNodes(TreeNode* A) {
    
    long long csum = 0, ucsum = 0;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            TreeNode* t = q.front();
            q.pop();
            if (i == 0 or i == sz-1) ucsum += t->val;
            else csum += t->val;
            
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
    return abs(csum - ucsum);
}
