// https://www.interviewbit.com/problems/min-cost-path/

/*

Problem Description

You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down.

Your target is to go from top left corner to the bottom right corner of the matrix.

But there are some restrictions while moving along the matrix:

If you follow what is written in the cell then you can move freely.
But if you don't follow what is written in the cell then you have to pay 1 unit of cost.
Like: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost.

So your task is to find the minimum cost to go from top-left corner to the bottom-right corner.



Problem Constraints
1 <= A,B <= 103
C[i][j] can be either U,R,L or D.


Input Format
First Argument represents a integer A (number of rows).
Second Argument represents a integer B (number of columns).
Third Argument represents a string array C which contains A strings each of length B.


Output Format
 Return an integer denoting the minimum cost to travel from top-left corner to bottom-right corner.



Example Input
Input:1

 A = 3
 B = 3
 C = ["RRR","DDD","UUU"]
Input:2

 A = 1
 B = 4
 C = ["LLLL"]


Example Output
Output-1 :

 1
Output-2 :

 3


Example Explanation*
Explanation for Input-1:

 Matrix looks like: RRR
                    DDD
                    UUU
 We go right two times and down two times.
 So from top-right cell we are going down though right is given so this incurs a cost of 1.
Explanation for Input-2:

 Matrix looks like: LLLL
 We go right three times.
 
 */


#define F first
#define S second
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int Solution::solve(int A, int B, vector<string> &s) {
    int n=s.size(),m=s[0].size();
    deque<pair<int,int>>dq;
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) dist[i][j]=1e9;
    }
    dist[0][0]=0;
    dq.push_back({0,0});
    while(!dq.empty()){
        pair<int,int>p=dq.front(); dq.pop_front();
        int x=p.F,y=p.S;
        char dir=s[p.F][p.S];
        if(dir=='U') x--;
        else if(dir=='D') x++;
        else if(dir=='R') y++;
        else y--;
        if(x>=0 and y>=0 and x<n and y<m and dist[x][y]>dist[p.F][p.S]){
            dist[x][y]=dist[p.F][p.S];
            dq.push_front({x,y});
        }
        for(int i=0;i<4;i++){
            x=p.F+dx[i];
            y=p.S+dy[i];
            if(x>=0 and y>=0 and x<n and y<m and dist[x][y]>dist[p.F][p.S]+1){
                dist[x][y]=1+dist[p.F][p.S];
                dq.push_back({x,y});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout<<dist[i][j]<<" "; 
            cout<<endl;
        }
        // if(dist[n-1][m-1]!=1e9) return dist[n-1][m-1]; this would you give a wrong answer
    }
    return dist[n-1][m-1];
}
