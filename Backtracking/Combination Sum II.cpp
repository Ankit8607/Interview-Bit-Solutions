/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.

*/


void rec(int level,vector<int> &A,vector<vector<int>>&ans, vector<int>&v,int B){
    if(level==A.size()){
        if(B==0) ans.push_back(v);
        return;
    }
    if(B-A[level]>=0){
        v.push_back(A[level]);
        rec(level+1,A,ans,v,B-A[level]);
        v.pop_back();
    }
    while(level+1<A.size() and A[level]==A[level+1]) level++;
    rec(level+1,A,ans,v,B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end());
    vector<vector<int>>ans;
    vector<int>v;
    rec(0,A,ans,v,B);
    return ans;
}
