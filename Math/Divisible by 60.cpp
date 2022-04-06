/*

Given a large number represent in the form of an integer array A, where each element is a digit.

You have to find whether there exists any permutation of the array A such that the number becomes divisible by 60.

Return 1 if it exists, 0 otherwise.



Problem Constraints
1 <= |A| <= 105
0 <= Ai <= 9


Input Format
The first argument is an integer array A.


Output Format
Return a single integer '1' if there exists a permutation, '0' otherwise.


Example Input
Input 1:
A = [0, 6]
Input 2:

A = [2, 3]


Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
We can rearrange the digits to form 60, which is divisible by 60.
Explanation 2:

There are only two possible permutations: [23, 32].
Both of them are not divisible by 60.

*/

// smart way

int Solution::solve(int a) {
    int g=sqrt(2*a);
    return (2*a>=(g*(g+1))?g:g-1);
}

// other way

int Solution::divisibleBy60(vector<int> &A) {
    if(A.size()==1 and A[0]==0) return 1;
    int sum=0;
    int even=0;
    int che=0;
    for(auto i:A){
        if(i==0) che=1;
        if(i%2==0) even++;
        sum+=i;
    }
    if(che and even>1 and sum%3==0) return 1;
    return 0;
}
