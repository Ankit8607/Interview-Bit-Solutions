// https://www.interviewbit.com/problems/repeating-subsequence/

/*

Problem Description

Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.



Problem Constraints
 1 <= |A| <= 100



Input Format
The first and the only argument of input contains a string A.



Output Format
Return an integer, 0 or 1:

    => 0 : False
    => 1 : True


Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "ab" is repeated.
Explanation 2:

 There is no repeating subsequence.
 
*/



int Solution::anytwo(string A) {
    int n = A.size();
    string B=A;
    vector <vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1] && i!=j) dp[i][j]= 1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            //cout<<dp[i][j]<<' ';
        }
       // cout<<endl;
    }
   if(dp[n][n]>1) return 1;
   else return 0;
}
