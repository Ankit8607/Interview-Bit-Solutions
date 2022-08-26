// https://www.interviewbit.com/problems/minimum-difference-subsets/

/*

Problem Description

Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.


Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.



Example Input
Input 1:

 A = [1, 6, 11, 5]


Example Output
Output 1:

 1


Example Explanation
Explanation 1:

 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11


*/


int dp[101][10010];
int rec(int level,vector<int>&A,int cursum,int sum){
    if(level==A.size()) return abs(sum-cursum);
    
    if(dp[level][cursum]!=-1) return dp[level][cursum];
    
    return dp[level][cursum]=min(rec(level+1,A,cursum,sum+A[level]),rec(level+1,A,cursum+A[level],sum));
}

int Solution::solve(vector<int> &A) {
    memset(dp,-1,sizeof(dp));
    return rec(0,A,0,0);
}
