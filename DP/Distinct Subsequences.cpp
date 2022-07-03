// https://www.interviewbit.com/problems/distinct-subsequences/

/*

Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
    
*/



string a,b;
int dp[705][705];

int rec(int i,int j){
    if(j==b.size()) return 1;
    if(i==a.size()) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int &ans=dp[i][j];
    ans=0;
    if(a[i]==b[j]) ans=rec(i+1,j+1);
    ans+=rec(i+1,j);
    
    return ans;
}

int Solution::numDistinct(string A, string B) {
    a=A; b=B;
    if(a.size()==b.size()) return a==b;
    memset(dp,-1,sizeof(dp));
    return rec(0,0);
}
