// https://www.interviewbit.com/problems/subset-sum-problem/

int rec(int level,int sum,vector<int>&arr,vector<vector<int>>&dp){
    if(sum==0) return 1;
    if(level==arr.size()) return 0;
    
    if(dp[level][sum]!=-1) return dp[level][sum];
    
    int ans=rec(level+1,sum,arr,dp);
    if(sum>=arr[level]) ans|=rec(level+1,sum-arr[level],arr,dp);
    
    return dp[level][sum]=ans;   
}

int Solution::solve(vector<int> &A, int B) {
    int sum=0;
    for(auto i:A) sum+=i;
    if(sum<B) return 0;
    vector<vector<int>>dp(A.size(),vector<int>(sum+1,-1));
    return rec(0,sum,A,dp);
}
