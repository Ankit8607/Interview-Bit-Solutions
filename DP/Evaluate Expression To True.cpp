// https://www.interviewbit.com/problems/evaluate-expression-to-true/

int mod=1003;
int rec(int l,int r, int state,string s,vector<vector<vector<int>>>&dp){
    if(l==r) return s[l]=='T'?state : 1-state;
    
    if(dp[l][r][state]!=-1) return dp[l][r][state];
    
    int ans = 0;
    for(int i=l+1;i<=r;i+=2){
        int t=rec(l,i-1,1,s,dp),f=rec(l,i-1,0,s,dp),t2=rec(i+1,r,1,s,dp), f2=rec(i+1,r,0,s,dp);
        if(s[i]=='|' and state) ans+=t*(t2+f2)+t2*f;
        else if(s[i]=='|') ans+=f*f2;
        else if(s[i]=='&' and state) ans+=t*t2;
        else if(s[i]=='&') ans+=t*f2+f*t2+f2*f;
        else if(s[i]=='^' and state) ans+=t*f2+t2*f;
        else ans+=t*t2 + f*f2;
    }
    
    return dp[l][r][state]=ans%mod;
}

int Solution::cnttrue(string A) {
    int n=A.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return rec(0,n-1,1,A,dp);
}
