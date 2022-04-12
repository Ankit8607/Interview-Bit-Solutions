/*

You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

Input

Only argument given is string S.
Output

Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
Constraints

1 <= length(S) <= 1e6
S can have special characters
Example

Input
    ABEC

Output
    6
    
*/


int mod=10003;
int Solution::solve(string s) {
    int ans=0,n=s.size();
    for(int i=0;i<n;i++){
        s[i]=tolower(s[i]);
        if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
            ans=(ans+n-i)%mod;
        }
    }
    return ans;
}
