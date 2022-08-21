// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

/*

Problem Description
 
 

There are a total of A courses you have to take, labeled from 1 to A.
Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
The pairs are given as two arrays B and C, where [B[i], C[i]] form a pair.

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.


Problem Constraints
1 <= A <= 64
1 <= length(B) = length(C) <= 1e5
1 <= B[i], C[i] <= A


Input Format
The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.


Output Format
Return a boolean value:
1 : If it is possible to complete all the courses.
0 : If it is not possible to complete all the courses.


Example Input
Input 1:
A = 3
B = [1, 2]
C = [2, 3]
Input 2:

A = 2
B = [1, 2]
C = [2, 1]


Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
It is possible to complete the courses in the following order:
1 -> 2 -> 3
Explanation 2:

It is not possible to complete all the courses.

*/


int Solution::solve(int n, vector<int> &A, vector<int> &B) {
    int tot=0;
    int indeg[n+1]={0};
    vector<int>g[n+1];
    for(int i=0;i<A.size();i++){
        g[A[i]].push_back(B[i]);
        indeg[B[i]]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(indeg[i]==0) q.push(i);
    tot=q.size();
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto i:g[cur]){
            indeg[i]--;
            if(indeg[i]==0){
                tot++;
                q.push(i);
            }
        }
    }
    return tot==n;
}
