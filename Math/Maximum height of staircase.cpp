/*

Given an integer A representing the number of square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks.

The first stair would require only one block, the second stair would require two blocks and so on.

Find and return the maximum height of the staircase.



Problem Constraints
0 <= A <= 109


Input Format
The only argument given is integer A.



Output Format
Return the maximum height of the staircase using these blocks.



Example Input
Input 1:

 A = 10
Input 2:

 20


Example Output
Output 1:

 4
Output 2:

 5
 
 
*/

// samrt way

int Solution::solve(int a) {
    int g=sqrt(2*a);
    return (2*a>=(g*(g+1))?g:g-1);
}


// other way

int Solution::solve(int A) {
    int ans=0;
    int lo=0,hi=2*A;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if((1LL*mid*mid+mid)<=2*A){
            lo=mid+1;
            ans=mid;
        }
        else hi=mid-1;
    }
    return ans;
}
