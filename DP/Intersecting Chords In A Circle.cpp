// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

/*

Given a number A, return number of ways you can draw A chords in a circle with 2 x A points such that no 2 chords intersect.

Two ways are different if there exists a chord which is present in one way and not in other.

Return the answer modulo 109 + 7.



Input Format:

The first and the only argument contains the integer A.
Output Format:

Return an integer answering the query as described in the problem statement.
Constraints:

1 <= A <= 1000
Examples:

Input 1:
    A = 1

Output 1:
    1

Explanation 1:
    If points are numbered 1 to 2 in clockwise direction, then different ways to draw chords are:
    {(1-2)} only.
    So, we return 1.

Input 2:
    A = 2

Output 2:
    2

Explanation 2:
    If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
    {(1-2), (3-4)} and {(1-4), (2-3)}.
    So, we return 2.
    
*/
    
    
    int mod=1e9+7;
int dp[1010];
int rec(int chords){
    if(chords<=1) return 1;
    
    if(dp[chords]!=-1) return dp[chords];
    
    int ans=0;
    for(int i=0;i<chords;i+=1){
        ans+=1LL*rec(i)*rec(chords-i-1)%mod;
        ans%=mod;
    }
    return dp[chords]=ans%mod;
}

int Solution::chordCnt(int A) {
    memset(dp,-1,sizeof(dp));
    return rec(A);
}
