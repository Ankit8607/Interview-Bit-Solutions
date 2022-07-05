// https://www.interviewbit.com/problems/ways-to-decode/
/*

Problem Description
 
 

A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.



Problem Constraints
1 <= |A| <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return a single integer denoting the total number of ways to decode it modulo 109 + 7.



Example Input
Input 1:

 A = "8"
Input 2:

 A = "12"


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.
 
 */


int mod=1e9+7;
int Solution::numDecodings(string s) {
    int n=s.size();
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=s[0]!='0';
    for(int i=2;i<=n;i++){
        if(s[i-1]=='0'){
            if(s[i-2]=='1' || s[i-2]=='2') dp[i]+=dp[i-2];
            continue;
        }
        dp[i]+=dp[i-1];
        if(s[i-2]=='1') dp[i]+=dp[i-2];
        else if(s[i-2]=='2' and s[i-1]<='6') dp[i]+=dp[i-2];
        dp[i]%=mod;
    }
    return dp[n];
}
