// https://www.interviewbit.com/problems/longest-common-subsequence/

/*

Problem Description

Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= |A|, |B| <= 1005



Input Format
First argument is an string A.

Second argument is an string B.



Output Format
Return the length of such longest common subsequence between string A and string B.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"


Example Output
Output 1:

 5


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5


*/


string a,b;
int dp[1010][1010];
int rec(int i,int j){
    if(i==a.size() || j==b.size()) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=rec(i+1,j);

    if(a[i]==b[j]) ans=max(ans,1+rec(i+1,j+1));
    else ans=max(ans,rec(i,j+1));
    
    return dp[i][j]=ans;
}

int Solution::solve(string A, string B) {
    a=A; b=B;
    memset(dp,-1,sizeof(dp));
    return rec(0,0);
}
