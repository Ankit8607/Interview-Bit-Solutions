// https://www.interviewbit.com/problems/tiling-with-dominoes/

/*

Problem Description
 
 

Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

NOTE:

See the sample explanation for better understanding.


Problem Constraints
1 <= A <= 105



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the number of ways to fill a 3 x A board with 2 x 1 dominoes with modulo 109 + 7.



Example Input
Input 1:

 2
Input 2:

 1


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 Following are all the 3 possible ways to fill up a 3 x 2 board.
 
Explanation 2:

 Not a even a single way exists to completely fill the grid of size 3 x 1.
 
 */


int n,mod=1e9+7;
int dp[100010][10];

int rec(int level,int state){
    if(level==n){
        if(state==0) return 1;
        return 0;
    }
    if(level>n) return 0;
    
    if(dp[level][state]!=-1) return dp[level][state];
    
    int &ans=dp[level][state];
    ans=0;
    if(state==0) ans+=(rec(level+1,1) + rec(level+1,4))%mod + rec(level+1,7);
    else if(state==1) ans+=rec(level+1,6) + rec(level+1,0);
    else if(state==2) ans+=rec(level+1,5);   // we will never face this state
    else if(state==3) ans+=rec(level+1,4);
    else if(state==4) ans+=rec(level+1,3) + rec(level+1,0);
    else if(state==5) ans+=rec(level+1,2);   // also we will never face this state
    else if(state==6) ans+=rec(level+1,1);
    else ans+=rec(level+1,0);
    
    ans=ans%mod;
    return ans;
}

int Solution::solve(int A) {
    if(A%2) return 0;
    n=A;
    memset(dp,-1,sizeof(dp));
    return rec(0,0);
}
