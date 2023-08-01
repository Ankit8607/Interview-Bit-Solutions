// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int rec(int i,int j, int n,int m, vector<vector<int>>&nums,vector<vector<int>>&dp){
    if(i>=n || j>=m) return 1e9;
    if(i==(n-1) and j==(m-1)) return nums[i][j];
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    return dp[i][j]=nums[i][j]+min(rec(i+1,j,n,m,nums,dp),rec(i,j+1,n,m,nums,dp));
}

int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return rec(0,0,n,m,A,dp);
}

