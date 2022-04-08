/*

You are given a 2D string array A of dimensions N x 2,

where each row consists of two strings: first is the name of the student, second is their marks.

You have to find the maximum average mark. If it is a floating point, round it down to the nearest integer less than or equal to the number.



Problem Constraints
1 <= N <= 105


Input Format
The first argument is a 2D string array A.


Output Format
Return a single integer which is the highest average mark.


Example Input
Input 1:
A = [["Bob", "80"], ["Bob", "90"], ["Alice", "90"]]
Input 2:

A = [["Bob", "80"], ["Bob", "90"], ["Alice", "90"], ["Alice", "10"]]


Example Output
Output 1:
90
Output 2:

85


Example Explanation
Explanation 1:
Alice has the highest average with 90 marks.
Explanation 2:

Bob has the highest average with 85 marks.

*/


int Solution::highestScore(vector<vector<string> > &A) {
    map<string,pair<int,int>>mp;
    for(int i=0;i<A.size();i++){
        mp[A[i][0]].first+=stoi(A[i][1]);
        mp[A[i][0]].second++;
    }
    int ans=0;
    for(auto i:mp){
        ans=max(ans,i.second.first/i.second.second);
    }
    return ans;
}
