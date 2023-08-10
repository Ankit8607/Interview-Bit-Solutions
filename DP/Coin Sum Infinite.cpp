// https://www.interviewbit.com/problems/coin-sum-infinite/

int mod=1000007;
int rec(vector<int>& a,int rem,vector<int>&dp){
    if(rem<0) return 0;
    if(rem==0) return 1;
    
    if(dp[rem]!=-1) return dp[rem];
    
    int ans=0;
    for(auto i:a) if(i!=rem) ans+=(1LL*rec(a,rem-i,dp)*rec(a,i,dp))%mod; else ans++;
    
    return dp[rem]=ans%mod;
}

int Solution::coinchange2(vector<int> &A, int B) {
     int n = A.size();

    int mod = 1000007;

    vector<int> dp(B+1,0);

    dp[0] = 1;

    for (int i=1; i<=n; i++) {
        
        for (int j=1; j<=B; j++) {

            if (j >= A[i-1]) {

                dp[j] = (dp[j] + dp[j - A[i-1]]) % mod;

            }

        }

    }

    return dp[B];
}
