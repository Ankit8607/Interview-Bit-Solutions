// https://www.interviewbit.com/problems/edit-distance/

/*

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
    

*/


string a,b;
int dp[500][500];

int rec(int i,int j){
    if(i==a.size()) return b.size()-j;
    if(b.size()==j) return a.size()-i;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=1e7;
    if(a[i]==b[j]) ans=rec(i+1,j+1);
    else{
        ans=1+rec(i,j+1);
        ans=min(ans,1+rec(i+1,j));
        ans=min(ans,1+rec(i+1,j+1));
    }

    return dp[i][j]=ans;
}

int Solution::minDistance(string A, string B) {
    a=A; b=B;
    memset(dp,-1,sizeof(dp));
    return rec(0,0);
}
