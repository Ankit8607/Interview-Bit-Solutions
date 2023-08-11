// https://www.interviewbit.com/problems/hotel-service/

vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {
    queue<pair<int,int>>q;
    int n=A.size(),m=A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]) q.push({i,j}),A[i][j]=-1;
        }
    }
    
    vector<int>ans(B.size());
    map<pair<int,int>,vector<int>>mp;
    for(int i=0;i<B.size();i++) mp[{B[i][0]-1,B[i][1]-1}].push_back(i);
    
    int dep=0;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    while(!q.empty()){
        queue<pair<int,int>>tmp;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(mp.count({i,j})) for(auto l: mp[{i,j}]) ans[l]=dep;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 and y>=0 and x<n and y<m and A[x][y]==0){
                    A[x][y]=-1;
                    tmp.push({x,y});
                }
            }
        }
        q=tmp;
        dep++;
    }
    return ans;
}


