// https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/

/*

Problem Description
 
 

GIven three prime numbers A, B and C and an integer D.

You need to find the first(smallest) D integers which only have A, B, C or a combination of them as their prime factors.



Input Format
First argument is an integer A.

Second argument is an integer B.

Third argument is an integer C.

Fourth argument is an integer D.



Output Format
Return an array of size D denoting the first smallest D integers which only have A, B, C or a combination of them as their prime factors.

NOTE: You need to return the array sorted in ascending order.



Example Input
Input 1:

 A = 2
 B = 3
 C = 5
 D = 5


Example Output
Output 1:

 [2, 3, 4, 5, 6]


Example Explanation
Explanation 1:

 4 = A * A i.e ( 2 * 2 ) 
 6 = A * B i.e ( 2 * 3 )
 
 */


vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int>ans(D+1);
    ans[0]=1;
    int a=0,b=0,c=0;
    for(int i=0;i<D;i++){
        int tmpa=ans[a]*A,tmpb=ans[b]*B,tmpc=ans[c]*C;
        if(tmpa<=tmpb and tmpa<=tmpc){
            a++;
            ans[i+1]=tmpa;
            if(tmpb==tmpa) b++;
            if(tmpc==tmpa) c++;
        }
        else if(tmpb<=tmpc){
            b++;
            ans[i+1]=(tmpb);
            if(tmpb==tmpc) c++;
        }
        else{
            ans[i+1]=(tmpc);
            c++;
        }
    }
    ans.erase(ans.begin());
    return ans;
}
