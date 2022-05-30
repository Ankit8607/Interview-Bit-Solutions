// https://www.interviewbit.com/problems/meeting-point/

/*

Problem Description

You and your friend decided to meet at one of the N locations in the town. The ith location is located at (A[i][0], A[i][1]) on an infinite 2D grid.

You want to meet at the location with minimum x-coordinate. If there are multiple such locations, choose the one with the minimum y-coordinate. If there are still multiple such locations, you can choose any of them.

Your friend wants to meet at the location with minimum y-coordinate. If there are multiple such locations, choose the one with the minimum x-coordinate. If there are still multiple such locations, you can choose any of them.   

Now, you need to find the distance between these two locations. The distance between (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2| where |a| is the absolute value of a.



Problem Constraints
2 <= N <= 2 x 105 

1 <= A[i][0], A[i][1] <= 109

There maybe multiple locations with the same coordinates.



Input Format
The first and only argument contains an integer array A of size N x 2.


Output Format
Return a single integer, the answer to the problem.


Example Input

  Input 1:

  A : 
  [
    [10, 10]
    [2, 9]
    [4, 6]
  ]
Input 2:
  A : 
  [
    [1, 3]
    [7, 5]
  ]


Example Output

  Output 1:

  5
Output 2:
  0


Example Explanation

  Explanation 1:

  You will meet at (2, 9). Friend wants to meet at (4, 6). Distance between them is |2 - 4| + |9 - 6| = 5.
Explanation 2:
  (1, 3) has both minimum x and y coordinate.


*/


int Solution::solve(vector<vector<int> > &A) {
    int a=1e9,b=1e9,c=1e9,d=1e9;
    for(int i=0;i<A.size();i++){
        if(A[i][0]<a) a=A[i][0],b=A[i][1];
        else if(A[i][0]==a and A[i][1]<b) b=A[i][1];

        if(A[i][1]<d) c=A[i][0],d=A[i][1];
        else if(A[i][1]==d and A[i][0]<c) c=A[i][0];
    }
    return abs(a-c)+abs(b-d);
}
