// https://www.interviewbit.com/problems/path-in-matrix/

int Solution::checkPath(vector<vector<int> > &A) {
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    int n=A.size(),m=A[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    pair<int,int>end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1) q.push({i,j}),vis[i][j]=1;
            else if(A[i][j]==2) end={i,j};
        }
    }
    
    while(!q.empty()){
        int i=q.front().first, j=q.front().second;
        q.pop();
        if(end==make_pair(i,j)) return 1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 and y>=0 and x<n and y<m and !vis[x][y] and A[x][y]){
                vis[x][y]=1;
                q.push({x,y});
            }
        }
    }
    return 0;
}
