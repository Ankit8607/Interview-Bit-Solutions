// https://www.interviewbit.com/problems/interleaving-strings/

/*

Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

Input 2:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbbaccc"

Output 2:
    0

Explanation 2:
    It is not possible to get C by interleaving A and B.
    
*/


string a,b,c;
int dp[1001][1001];

int rec(int i,int j,int k){
    if(k==c.size()) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int &ans=dp[i][j];
    ans=0;
    if(i<a.size() and a[i]==c[k] and rec(i+1,j,k+1)) return ans=1;
    if(j<b.size() and b[j]==c[k] and rec(i,j+1,k+1)) return ans=1;
    return ans;
}

int Solution::isInterleave(string A, string B, string C) {
    a=A,b=B,c=C;
    memset(dp,-1,sizeof(dp));
    if(a.size()+b.size()!=c.size()) return 0;
    return rec(0,0,0);
}
