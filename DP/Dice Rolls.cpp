// https://www.interviewbit.com/problems/dice-rolls/

vector<int>dp;
int mod=1e9+7;
int rec(int A){
    if(A<0) return 0;
    if(A<=1) return 1;
    
    if(dp[A]!=-1) return dp[A];
    
    return dp[A]=(((((rec(A-1)+rec(A-2))%mod+rec(A-3))%mod+rec(A-4))%mod+rec(A-5))%mod+rec(A-6))%mod; 
}

int Solution::solve(int A) {    
    dp.resize(A+1,-1);
    return rec(A);
}
