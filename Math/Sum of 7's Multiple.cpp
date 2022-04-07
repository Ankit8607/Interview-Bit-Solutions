/*

Given a range [A, B], find sum of integers divisible by 7 in this range.


Problem Constraints
1 <= A <= B <= 109


Input Format
First argument is an integer A.
Second argument is an integer B.


Output Format
Return an integer.


Example Input
Input 1:
A = 1
B = 7
Input 2:
A = 99
B = 115


Example Output
Output 1:
7
Output 2:
217


Example Explanation
Explanation 1:
Integers divisible by 7 in given range are {7}.
Explanation 2:
Integers divisible by 7 in given range are {105, 112}.

*/


long long sum(int a,int b){
    long long ans=b+1;
    ans*=b;
    ans/=2;
    return ans*7;
}

long Solution::solve(int A, int B) {
    long long a=sum(1,(A-1)/7);
    long long b=sum(1,B/7);
    long long res=b-a;
    return res;
}
