/*

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :

If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.

Example : itertools.combinations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.

*/



void rec(int level, int A, int B, vector<vector<int>> &ans, vector<int>&v){
    if(B==0){
        ans.push_back(v);
        return;
    }
    if(level>A) return;
    if(B){
        v.push_back(level);
        rec(level+1,A,B-1,ans,v);
        v.pop_back();
    }
    rec(level+1,A,B,ans,v);
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>>ans;
    vector<int>v;
    rec(1,A,B,ans,v);
    return ans;
}
