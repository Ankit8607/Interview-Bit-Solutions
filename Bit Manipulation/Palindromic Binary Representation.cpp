/*

Problem Description

Given an integer A find the Ath number whose binary representation is a palindrome.

NOTE:

Consider the 1st number whose binary representation is palindrome as 1, instead of 0
Do not consider the leading zeros, while considering the binary representation.


Problem Constraints
 1 <= A <= 2104



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the Ath number whose binary representation is a palindrome.



Example Input
Input 1:

 A = 1
Input 1:

 A = 9


Example Output
Output 1:

 1
Output 2:

 27


Example Explanation*
Explanation 1:

 1st Number whose binary representation is palindrome is 1
Explanation 2

 9th Number whose binary representation is palindrome is 27 (11011)
 
 */


int Solution::solve(int A) {
    int prev=0,ans=1;
    for(int i=0;i<32;i++){
        long long int x=(1<<(i/2));
        if(prev+x>=A){ 
            ans|=(1<<i);
            bool flag=0;
            for(int j=i-1;j>=(i+1)/2;j--){ 
                if(prev+x/2>=A&&flag!=1){
                    if(prev+x/2==A){
                        flag=1;
                    }
                }
                else{
                    ans|=(1<<j);
                    ans|=(1<<(i-j)); 
                    prev+=x/2;
                }
                x/=2;
            } return ans;
        }
        prev+=x;
    }
    return ans;
}
