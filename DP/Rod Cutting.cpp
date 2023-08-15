// https://www.interviewbit.com/problems/rod-cutting/

#define ii pair<int,int>
ii rec(int l,int r,int n,vector<int>&cuts,vector<vector<ii>>&dp){
    if(l>r) return {0,-1};
    
    if(dp[l][r]!=make_pair(-1,-1)) return dp[l][r];
    
    int ans=1e9,cut=0;
    int a=(r==(int)cuts.size()-1?n:cuts[r+1]);
    int b=l==0?0:cuts[l-1];
    int len=a-b;
    for(int i=l;i<=r;i++){
        int t=len+rec(l,i-1,n,cuts,dp).first+rec(i+1,r,n,cuts,dp).first;
        if(t<ans){
            ans=t;
            cut=i;
        }
    }
    
    return dp[l][r]={ans,cut};
}

void back(int l,int r,vector<vector<ii>>&dp,vector<int>&ans,vector<int>&arr){
    if(l>r) return;
    
    int i=dp[l][r].second;
    ans.push_back(arr[i]);
    back(l,i-1,dp,ans,arr);
    back(i+1,r,dp,ans,arr);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    sort(B.begin(),B.end());
    int n=B.size();
    vector<vector<ii>>dp(n,vector<ii>(n));
    for(auto &i:dp)
        for(auto &j:i) j={-1,-1};
    rec(0,n-1,A,B,dp);
    vector<int>ans;
    back(0,n-1,dp,ans,B);
    return ans;
}
