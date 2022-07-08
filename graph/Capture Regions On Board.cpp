// https://www.interviewbit.com/problems/capture-regions-on-board/

/*

Problem Description

Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 103



Input Format
First and only argument 2D character matrix A of size N X M.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [  [X, X, X, X],
        [X, O, O, X],
        [X, X, O, X],
        [X, O, X, X]
     ]


Example Output
Output 1:

 A = [  [X, X, X, X],
        [X, X, X, X],
        [X, X, X, X],
        [X, O, X, X]
     ]


Example Explanation
Explanation 1:

 'O' in (4,2) is not surrounded by X from below.
 
 */


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int i,int j,vector<vector<char> > &A,vector<vector<bool> > &vis,int n ,int m){
    if(vis[i][j]) return;
    vis[i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 and y>=0 and x<=n-1 and y<=m-1 and A[x][y]=='O')
            dfs(x,y,A,vis,n,m);
    }   
}

void Solution::solve(vector<vector<char> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<m;i++){
        if(A[0][i]=='O') dfs(0,i,A,vis,n,m);
        if(A[n-1][i]=='O') dfs(n-1,i,A,vis,n,m);
    }
    for(int j=0;j<n;j++){
        if(A[j][0]=='O') dfs(j,0,A,vis,n,m);
        if(A[j][m-1]=='O') dfs(j,m-1,A,vis,n,m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O' and !vis[i][j]) A[i][j]='X'; 
        }
    }
}
