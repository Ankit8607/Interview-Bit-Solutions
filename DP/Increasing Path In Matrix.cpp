// https://www.interviewbit.com/problems/increasing-path-in-matrix/

/*

Problem Description
 
 

Given a 2D integer matrix A of size N x M.

 

 

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length possible if we start from the cell (0, 0) and want to reach cell (N - 1, M - 1).

NOTE:

 

 

If there doesn't exist a path return -1.


Problem Constraints
1 <= N, M <= 103

1 <= A[i][j] <= 108



Input Format
First and only argument is an 2D integer matrix A of size N x M.



Output Format
Return a single integer denoting the length of longest path in the matrix if no such path exists return -1.



Example Input
Input 1:

 A = [  [1, 2]
        [3, 4]
     ]
Input 2:

 A = [  [1, 2, 3, 4]
        [2, 2, 3, 4]
        [3, 2, 3, 4]
        [4, 5, 6, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Longest path is either 1 2 4 or 1 3 4.
Explanation 2:

 Longest path is 1 2 3 4 5 6 7.
 
 */



int n,m;
int dp[1001][1001];

int rec(int i,int j,vector<vector<int>>&A){
    if(i==n-1 and j==m-1) return 1;  
    if(i>=n ||j>=m) return -1;
    
    if(dp[i][j]!=-2) return dp[i][j];
    
    int ans=-1;
    if(i+1<n and A[i][j]<A[i+1][j]){
        if(rec(i+1,j,A)!=-1) ans=1+rec(i+1,j,A);  
    }
    
    if(j+1<m and A[i][j]<A[i][j+1]){
        if(rec(i,j+1,A)!=-1) ans=max(ans,1+rec(i,j+1,A));  
    }
    return dp[i][j]=ans;
    
}

int Solution::solve(vector<vector<int> > &A) {
    n=A.size();m=A[0].size();
    for(int i=0;i<1001;i++)
        for(int j=0;j<1001;j++)
            dp[i][j]=-2;
    return rec(0,0,A);
}
