// https://www.interviewbit.com/problems/merge-k-sorted-arrays/

/*

Problem Description

You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]


*/


vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int>ans;
    for(auto &i:A){
        for(auto &j:i) ans.push_back(j);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
