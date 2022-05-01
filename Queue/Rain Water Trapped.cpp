/*

Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0


Example Explanation
Explanation 1:

 
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:

 No water is trapped.
 
 */


int Solution::trap(const vector<int> &A) {
    int n=A.size();
    int right[n],mx=0;
    for(int i=n-1;i>=0;i--){
        right[i]=mx;
        mx=max(mx,A[i]);
    }
    int ans=0;
    mx=A[0];
    for(int i=1;i<n-1;i++){
        ans+=max(0,min(mx,right[i])-A[i]);
        mx=max(mx,A[i]);
    }
    return ans;
}
