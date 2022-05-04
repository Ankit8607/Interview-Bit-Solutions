/*

Problem Description
 
 

Given an array of candidate numbers A and a target number B, find all unique combinations in A where the candidate numbers sums to B.

The same repeated number may be chosen from A unlimited number of times.

Note:

1) All numbers (including target) will be positive integers.

2) Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

3) The combinations themselves must be sorted in ascending order.

4) CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR ... (a1 = b1 AND a2 = b2 AND ... ai = bi AND ai+1 > bi+1)

5) The solution set must not contain duplicate combinations.

 



Problem Constraints
1 <= |A| <= 20 

1 <= A[i] <= 50

1 <= B <= 500



Input Format
The first argument is an integer array A.

The second argument is integer B.



Output Format
 Return a vector of all combinations that sum up to B.



Example Input
Input 1:

A = [2, 3]
B = 2
Input 2:

A = [2, 3, 6, 7]
B = 7


Example Output
Output 1:

[ [2] ]
Output 2:

[ [2, 2, 3] , [7] ]


Example Explanation
Explanation 1:

All possible combinations are listed.
Explanation 2:

All possible combinations are listed.

*/


void backtracking(int start, vector<int>& row, int sum, vector<vector<int> >& res, vector<int>& A, int B)
{
    if (sum >= B)
    {
        if (sum==B)
            res.emplace_back(row);
        return;
    }
    
    if (start == A.size())
        return;
        
    row.emplace_back(A[start]);
    sum += A[start];
    backtracking(start, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();
    backtracking(start+1, row, sum, res, A, B);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> row, a;
    sort(A.begin(), A.end());
    
    a.emplace_back(A[0]);
    for (auto i = 1; i<A.size(); ++i)
        if (A[i-1] != A[i])
            a.emplace_back(A[i]);
    
    backtracking(0, row, 0, res, a, B);
    return res;
}
