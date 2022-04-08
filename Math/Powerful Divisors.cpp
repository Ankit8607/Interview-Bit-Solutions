/*

You are given an integer array A of length N.

For every integer X in the array, you have to find out the number of integers Y, 
such that 1 <= Y <= X, and the number of divisors of Y is a power of 2.

For example, 6 has the following divisors - [1, 2, 3, 6]. This is equal to 4, which is a power of 2.

On the other hand, 9 has the following divisors [1, 3, 9] which is 3, which is not a power of 2.

Return an array containing the answer for every X in the given array.



Problem Constraints
1 <= N <= 105
1 <= Amax <= 106
Sum of Amax over all test cases will not exceed 5 * 106


Input Format
The first argument is the integer array A.


Output Format
Return an array containing the answer for every X in the given array.


Example Input
Input 1:
A = [1, 4]
Input 2:

A = [5, 10]


Example Output
Output 1:
[1, 3]
Output 2:

[4, 8]


Example Explanation
Explanation 1:
The numbers 1, 2, 3 have the required number of divisors.
Explanation 2:

Only 4 and 9 are the numbers less than or equal to 10 which do not have the required number of divisors.

*/


vector<int> Solution::powerfulDivisors(vector<int> &A) {
    int mx=*max_element(A.begin(),A.end());
    int div[mx+1]={0};
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            div[j]++;
        }
    }
    // for(int i=1;i<=mx;i++) cout<<div[i]<<" ";
    for(int i=1;i<=mx;i++){
        if((div[i]&(div[i]-1))==0) div[i]=1;
        else div[i]=0;
        div[i]+=div[i-1];
    }
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        ans.push_back(div[A[i]]);
    }
    return ans;
}
