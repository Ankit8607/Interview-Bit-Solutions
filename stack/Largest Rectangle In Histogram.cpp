/*

Problem Description
 
 

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.

*/



int Solution::largestRectangleArea(vector<int> &A) {
    stack<int>l,r;
    int ind=0,n=A.size();
    int left[n],right[n];
    
    for(int i=0;i<n;i++){
        while(!l.empty() and A[l.top()]>=A[i]) l.pop();
        if(l.empty()) left[i]=-1;
        else left[i]=l.top();
        l.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(!r.empty() and A[r.top()]>=A[i]) r.pop();
        if(r.empty()) right[i]=n;
        else right[i]=r.top();
        r.push(i);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,1LL*(right[i]-left[i]-1)*A[i]);
    }
    return ans;
}
