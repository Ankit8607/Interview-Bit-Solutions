// https://www.interviewbit.com/problems/egg-drop-problem/

int rec(int eggs,int floor,vector<vector<int>>&dp){
    if(floor==1 || floor==0) return floor;
    if(eggs<=0) return 1e9;
    if(eggs==1) return floor;
    
    if(dp[eggs][floor]!=-1) dp[eggs][floor];
    
    // int ans=1e9;
    // for(int k=1;k<=floor;k++){
    //     ans=min(ans,max(rec(eggs-1,k-1,dp),rec(eggs,floor-k,dp)));
    // }
    
    int ans=1e9;
    int l=1,h=floor;
    while(h-l>1){
        int mid=(l+h)/2;
        int f1=rec(eggs-1,mid-1,dp);
        int f2=rec(eggs,floor-mid,dp);
        if(f1==f2) h=l=mid;
        else if(f1>f2) h=mid;
        else l=mid;
    }
    
    ans=1+max(rec(eggs-1,l-1,dp),rec(eggs,floor-l,dp));
    ans=1+min(ans,max(rec(eggs-1,h-1,dp),rec(eggs,floor-h,dp)));
    
    return dp[eggs][floor]=ans;
}

int Solution::solve(int A, int B) {
    vector<vector<int>>dp(A+1,vector<int>(B+1,-1));
    // return rec(A,B,dp);
    for(int i=0;i<=A;i++) dp[i][0]=0;
    for(int i=1;i<=B;i++) dp[0][i]=1e9;
    for(int i=1;i<=B;i++) dp[1][i]=i;
    
    for(int egg=2;egg<=A;egg++){
        int xopt=1;
        for(int floor=1;floor<=B;floor++){
            while(xopt<floor){
                int f1=dp[egg-1][xopt-1];
                int f2=dp[egg][floor-xopt];
                int m1=max(f1,f2);
                
                f1=dp[egg-1][xopt];
                f2=dp[egg][floor-xopt-1];
                int m2=max(f1,f2);
                
                if(m2<m1) xopt++;
                else break;
            }
            
            dp[egg][floor]=1+max(dp[egg-1][xopt-1],dp[egg][floor-xopt]);
        }
    }
    return dp[A][B];
}
