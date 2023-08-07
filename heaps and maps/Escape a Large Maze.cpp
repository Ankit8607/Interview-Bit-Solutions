// https://leetcode.com/problems/escape-a-large-maze/submissions/

class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};

    int dis(int i,int j,int a,int b){
        return abs(i-a)+abs(j-b);
    }

    bool rec(int i,int j,int a,int b,int c,int d, set<pair<int,int>> &st,set<pair<int,int>> &vis,int dist){
        if(i==c and j==d) return 1;
        if(i<0 || i>=1e6 || j<0 || j>=1e6 || st.find({i,j})!=st.end()) return 0;

        if(dis(i,j,a,b)>=dist) return 1;

        vis.insert({i,j});
        int ans=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(vis.find({x,y})==vis.end())
                ans|=rec(x,y,a,b,c,d,st,vis,dist);
        }

        return ans;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>>mp,vis;
        for(auto i: blocked)
            mp.insert(make_pair(i[0],i[1]));

        int ans=1;
        ans &= rec(source[0],source[1],source[0],source[1],target[0],target[1],mp,vis,blocked.size());
        vis.clear();
        
        ans &= rec(target[0],target[1],target[0],target[1],source[0],source[1],mp,vis,blocked.size());
        return ans;
    }
};
