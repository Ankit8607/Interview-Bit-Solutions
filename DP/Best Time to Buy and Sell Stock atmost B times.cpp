// https://www.interviewbit.com/problems/palindromic-substrings/

int rec(int level,int state,int rem,vector<int> &arr,vector<vector<vector<int>>>& dp){
    if(rem==0 || level==arr.size()) return 0;
    
    if(dp[level][rem][state]!=-1) return dp[level][rem][state];
    
    int ans=dp[level][rem][state];
    
    if(state==0) ans = max(rec(level+1,state,rem,arr,dp),rec(level+1,1,rem,arr,dp));
    if(state==1) ans = arr[level]-arr[level-1]+max(rec(level+1,state,rem,arr,dp),rec(level+1,0,rem-1,arr,dp));
    
    return ans;
}

int Solution::solve(vector<int> &a, int k) {
    // int t=min(B,(int)A.size()/2);
    // vector<vector<vector<int>>>dp(A.size(),vector<vector<int>>(t+1,vector<int>(2,-1)));
    // return rec(0,0,t,A,dp);
    int n = (int)a.size();
    if (2 * k > n)
    {
        long long ans = 0;
        for (long long i = 1; i < n; ++i)
            ans += max(0, a[i] - a[i - 1]);
        return ans;
    }
    else
    {
        long long dp[k + 1][n];
        memset(dp, 0, sizeof(dp));
        for (long long i = 1; i <= k; ++i)
        {
            long long m = -a[0];
            for (long long j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i][j - 1], a[j] + m);
                m = max(m, dp[i - 1][j - 1] - a[j]);
            }
        }
        return dp[k][n - 1];
    }
}
