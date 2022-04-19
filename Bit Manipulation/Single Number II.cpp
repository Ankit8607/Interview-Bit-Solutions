/*

Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer.
Constraints:

2 <= N <= 5 000 000  
0 <= A[i] <= INT_MAX
For Examples :

Example Input 1:
    A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Example Output 1:
    4
Explanation:
    4 occur exactly once
Example Input 2:
    A = [0, 0, 0, 1]
Example Output 2:
    1
    
*/


int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=0;i<31;i++){
        int cnt=0;
        for(int j=0;j<A.size();j++){
            if(A[j]&(1<<i))cnt++;
        }
        if(cnt%3) ans|=(1<<i);
    }
    return ans;
}
