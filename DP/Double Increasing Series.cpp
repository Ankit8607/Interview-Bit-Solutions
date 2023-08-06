// https://www.interviewbit.com/problems/double-increasing-series/

int mod=1e9+7;

int rec(int level, int num, int a,int b,vector<vector<int>>&dp){
    if(level+1==b) return ((num<=a)?(a-num+1):0);
    if(num>a) return 0;
    
    if(dp[level][num]!=-1) return dp[level][num];
    
    int ans=(rec(level,num+1,a,b,dp)+rec(level+1,num*2,a,b,dp))%mod;
    // int ans=0;
    // for(int i=num;i<=a;i++){
    //     int t=rec(level+1,i*2,a,b,dp);
    //     if(t==0) break;
    //     ans+=t;
    //     ans%=mod;
    // } 
    
    return dp[level][num]=ans;
}

int Solution::solve(int A, int B) {
    vector<vector<int>>dp(B,vector<int>(A+1,-1));
    return rec(0,1,A,B,dp);
}
