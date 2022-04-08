/*

Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110

Problem Approach:

Complete code in the hint.

*/



string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    string ans="";
    while(A){
        if(A%2==0) ans+='0';
        else ans+='1';
        A/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
