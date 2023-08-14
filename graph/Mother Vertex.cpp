// https://www.interviewbit.com/problems/mother-vertex/discussion/p/simple-dfs-solution-using-last-visited-vertex/393705/2594/

void DFS(int src, vector <bool> &vis,vector<vector<int>> &adj) {
    vis[src] = true;
    for (auto x: adj[src]) {
        if (!vis[x]) {
            DFS(x, vis,adj);
        }
    }
}
int Solution::motherVertex(int A, vector<vector<int>> &B) {
    vector<bool> vis(A+1,false);
    vector<vector<int>> adj(A+1);
    for (int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    int mother;
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            mother = i;
            DFS(i,vis,adj);
        }
    }
    for(int i=1;i<=A;i++) vis[i]=false;
    DFS(mother,vis,adj);
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
            return 0;
    }
    return 1;
}
