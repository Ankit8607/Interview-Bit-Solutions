// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

// int rec(int l,int r,string s,vector<vector<int>>&dp){
//     if(r>)
// }

// int Solution::minCut(string A) {
//     int n=A.size();
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     return rec(0,n-1,A,dp);
// }

unordered_map<string,int> mp;


bool isPalin(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return s == t;
}


int solve(string s)
{
    if(isPalin(s)) return 0;
    if(s.size() == 1) return 0;
    if(mp[s]) return mp[s];
    int n = s.size();
    int ans = INT_MAX;
    for(int i = 1; i<=n; i++)
    {
        string temp = s.substr(0,i);
        if(isPalin(temp))
        {
            ans = min(ans,1+solve(s.substr(i,n-i)));
        }
    }
    return mp[s] = ans;
   
}


int Solution::minCut(string A) {
   // memset(dp,"-1",sizeof dp);
   return solve(A);
}
