// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

/*

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers

is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

Input Format:

The first and the only argument of input contains a 2d matrix, A.
Output Format:

Return an integer, representing the maximum possible sum.
Constraints:

1 <= N <= 20000
1 <= A[i] <= 2000
Example:

Input 1:
    A = [   [1]
            [2]    ]

Output 1:
    2

Explanation 1:
    We will choose 2.

Input 2:
    A = [   [1, 2, 3, 4]
            [2, 3, 4, 5]    ]
    
Output 2:
    We will choose 3 and 5.
    
*/



int dp[20010][2];

int rec(int level,int prev,vector<vector<int>>&A){
    if(level==A[0].size()) return 0;
    
    if(dp[level][prev]!=-1) return dp[level][prev];
    int ans=rec(level+1,0,A);
    if(prev==0) ans=max(ans,max(A[0][level],A[1][level])+rec(level+1,1,A));
    
    return dp[level][prev]=ans;
}

int Solution::adjacent(vector<vector<int> > &A) {
    memset(dp,-1,sizeof(dp));
    return rec(0,0,A);
}
