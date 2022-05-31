// https://www.interviewbit.com/problems/longest-palindromic-subsequence/

/*

Problem Description
 
 

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
 1 <= |A| <= 1005



Input Format
First and only argument is an string A.



Output Format
Return a integer denoting the length of longest palindromic subsequence in A.



Example Input
Input 1:

 A = "bebeeed"


Example Output
Output 1:

 4


Example Explanation
Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4
 
 */



int dp[1010][1010];
string s;

int rec(int i,int j){
    if(i>=j){
        if(i==j) return 1;
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    if(s[i]==s[j]) ans=2+rec(i+1,j-1);
    else ans=max(rec(i,j-1),rec(i+1,j));
    
    return dp[i][j]=ans;
}

int Solution::solve(string A) {
    s=A;
    memset(dp,-1,sizeof(dp));
    return rec(0,s.size()-1);
}
