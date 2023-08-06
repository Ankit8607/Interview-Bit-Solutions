// https://leetcode.com/problems/longest-cycle-in-a-graph/description/

class Solution {
public:

    void dfs(int node, vector<int>&vis,vector<int>&edges,int dep,int &ans){
        if(edges[node]==-1 || vis[node]==-1) return;
        // cout<<"node= "<<node<<endl;
        if(vis[edges[node]]>0){ ans=max(ans,dep-vis[edges[node]]+1); return;}

        vis[node]=dep;
        dfs(edges[node],vis,edges,dep+1,ans);
        vis[node]=-1;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>vis(n,0);
        
        int ans=-1;
        for(int i=0;i<n;i++) dfs(i,vis,edges,1,ans);
        return ans;
    }
};
