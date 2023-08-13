// https://www.interviewbit.com/problems/arrange-ii/


int rec(int level,int rem,string &s,vector<vector<int>>&dp){
    if(level==s.size()) return rem==0?0:1e9;
    if(rem==0) return 1e9;
    
    if(dp[level][rem]!=-1) return dp[level][rem];
    
    int ans=1e9;
    int w=0,b=0;
    for(int i=level;i<s.size();i++){
        if(s[i]=='W') w++;
        else b++;
        ans=min(ans,w*b+rec(i+1,rem-1,s,dp));
    }
    
    return dp[level][rem]=ans;
}

int Solution::arrange(string A, int B) {
    if(A.size()<B) return -1;
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(B+1,-1));
    return rec(0,B,A,dp);
}
