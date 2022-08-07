// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

/*

Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

N = 2, S = 4 
 Valid numbers are {22, 31, 13, 40} 
 Hence output 4.
 
 */


const int mod=1e9+7;
int rec(int level,int n,int sum,int iszero,vector<vector<int>>&dp){
    if(level==n) return sum==0;
    
    if(dp[level][sum]!=-1) return dp[level][sum];
    
    int ans=0;
    int i=iszero==0;
    for(;i<=9;i++){
        if(i<=sum){
            ans+=rec(level+1,n,sum-i,1,dp);
            ans%=mod;
        }
    }
    return dp[level][sum]=ans%mod;
}

int Solution::solve(int A, int B) {
    vector<vector<int>>dp(A,vector<int>(B+1,-1));
    return rec(0,A,B,0,dp);
}
