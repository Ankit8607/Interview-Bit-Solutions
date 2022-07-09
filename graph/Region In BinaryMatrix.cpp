// https://www.interviewbit.com/problems/region-in-binarymatrix/

/*

Problem Description

Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.



Problem Constraints
 1 <= N, M <= 102

 A[i][j]=0 or A[i][j]=1



Input Format
First argument is a 2D binary matrix Aof size  N x M.



Output Format
Return a single interger denoting the length of largest region.



Example Input
Input 1:

 A = [  [0, 0, 1, 1, 0]
        [1, 0, 1, 1, 0]
        [0, 1, 0, 0, 0]
        [0, 0, 0, 0, 1]
    ]
Input 2:

 A = [  [1, 1, 1]
        [0, 0, 1]
    ]


Example Output
Output 1:

 6
Output 2:

 4


Example Explanation
Explanation 1:

 The largest region is denoted by red color in the matrix:
    00110
    10110
    01000
    00001
Explanation 2:

 The largest region is:
    111
    001
    
    */


int n,m;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={0,1,-1,1,-1,0,1,-1};
int dfs(int i,int j,vector<vector<int> > &A){
    int cnt=1;
    A[i][j]=0;
    for(int k=0;k<8;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<n and y<m and x>=0 and y>=0 and A[x][y]==1) cnt+=dfs(x,y,A);
    }
    return cnt;
}

int Solution::solve(vector<vector<int> > &A) {
    int ans=0;
    n=A.size(); m=A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1) ans=max(ans,dfs(i,j,A));
        }
    }
    return ans;
}
