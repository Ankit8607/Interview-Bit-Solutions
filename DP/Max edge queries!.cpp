// https://www.interviewbit.com/problems/max-edge-queries/

void dfs(int node, int par, int depth,int wt, vector<int>& dep, vector<vector<pair<int,int>>>&g, vector<vector<int>>& parent,vector<vector<int>>&dp){
    dep[node]=depth;
    parent[node][0]=par;
    dp[node][0]=wt;
    
    for(int j=1;j<20;j++){
        parent[node][j]=parent[parent[node][j-1]][j-1];
        dp[node][j]=max(dp[node][j-1],dp[parent[node][j-1]][j-1]);
    }
    
    for(auto i: g[node]){
        if(i.first!=par)
            dfs(i.first,node,depth+1,i.second,dep,g,parent,dp);
    }
}

int lca(int u,int v,vector<int>&dep, vector<vector<int>>&par,vector<vector<int>>&dp){
    if(dep[u]<dep[v]) swap(u,v);
    int jump=dep[u]-dep[v];
    int ans=0;
    for(int i=19;i>=0;i--){
        if(jump&(1<<i)){
            ans=max(ans,dp[u][i]);
            u=par[u][i];
        }
    }
    if(u==v) return ans;
    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            ans=max(ans,dp[u][i]);
            u=par[u][i];
            ans=max(ans,dp[v][i]);
            v=par[v][i];
        }
    }
    return max(ans,max(dp[u][0],dp[v][0]));
}

vector<int> Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int n=A.size();
    vector<vector<int>>parent(n+2,vector<int>(20,0)),dp(n+2,vector<int>(20,0));
    vector<vector<pair<int,int>>>g(n+2);
    for(auto i: A){
        g[i[0]].push_back({i[1],i[2]});
        g[i[1]].push_back({i[0],i[2]});
    }
    vector<int>dep(n+2,0);
    dep[0]=-1;
    dfs(1,0,0,0,dep,g,parent,dp);
    
    vector<int>ans;
    for(auto i: B) ans.push_back(lca(i[0],i[1],dep,parent,dp));
    
    return ans;
}
