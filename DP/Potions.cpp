// https://www.interviewbit.com/problems/potions/

int mod=100;

int rec(int l,int r,vector<vector<int>>&dp,vector<int>&arr,vector<int>& pre){
    if(r<=l) return 0;
    
    if(dp[l][r]!=-1) return dp[l][r];
    
    int ans=1e9;
    for(int i=l;i<r;i++)
        ans=min(ans,((pre[i]-(l==0?0:pre[l-1]))%mod)*((pre[r]-pre[i])%mod)+rec(l,i,dp,arr,pre)+rec(i+1,r,dp,arr,pre));
    
    return dp[l][r]=ans;
}

int Solution::minSmoke(vector<int> &A) {
    vector<vector<int>>dp(A.size(),vector<int>(A.size(),-1));
    vector<int>pre(A.size());
    pre[0]=A[0];
    for(int i=1;i<A.size();i++) pre[i]=pre[i-1]+A[i];
    return rec(0,A.size()-1,dp,A,pre);
}
