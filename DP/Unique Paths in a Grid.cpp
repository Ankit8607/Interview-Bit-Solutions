// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int rec(int i,int j, int n,int m, vector<vector<int>>&nums,vector<vector<int>>& dp){
    if(i>=n || j>=m || nums[i][j]) return 0;
    if(i==(n-1) and j==(m-1)) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j]=rec(i+1,j,n,m,nums,dp)+rec(i,j+1,n,m,nums,dp);
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return rec(0,0,n,m,A,dp);
}
