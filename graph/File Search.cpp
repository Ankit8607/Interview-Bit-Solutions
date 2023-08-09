// https://www.interviewbit.com/problems/file-search/

void dfs(int node,vector<vector<int>>&g,vector<int>&vis){
    // if(vis[node]) return;
    
    vis[node]=1;
    for(auto i: g[node]) if(!vis[i]) dfs(i,g,vis);
}

int find(int node,vector<int>&parent){
    if(parent[node]==node) return node;
    
    return find(parent[node],parent);
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    vector<int>parent(A+1),rank(A+1,1);
    for(int i=1;i<=A;i++) parent[i]=i;
    int ans=A;
    
    for(auto i: B){
        int p1=find(i[0],parent);
        int p2=find(i[1],parent);
        if(p1!=p2){
            ans--;
            if(rank[p1]>rank[p2]) parent[p2]=p1,rank[p1]+=rank[p2];
            else parent[p1]=p2,rank[p2]+=rank[p1];
        }
    }
    // vector<vector<int>>g(A+1,vector<int>(A+1));
    // int ans=0;
    // for(auto i:B){
    //     g[i[0]].push_back(i[1]);
    //     g[i[1]].push_back(i[0]);
    // }
    
    // for(int i=1;i<=A;i++){
    //     if(!vis[i]) ans++,dfs(i,g,vis);
    // }
    // return ans;
    return ans;
}
