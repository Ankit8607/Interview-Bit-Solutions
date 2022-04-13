/*

Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return a integer denoting the minimum characters to be appended (insertion at end) to make the string A a palindrome.



Example Input
Input 1:

 A = "abede"
Input 2:

 A = "aabb"


Example Output
Output 1:

 2
Output 2:

 2


Example Explanation
Explanation 1:

 We can make string palindrome as "abedeba" by adding ba at the end of the string.
Explanation 2:

 We can make string palindrome as "aabbaa" by adding aa at the end of the string.
 
 */


int Solution::solve(string A) {
    string tmp=A;
    reverse(tmp.begin(),tmp.end());
    string s=tmp+"#"+A;
    int n=s.size();
    int kmp[n]; kmp[0]=0;
    int j=0;
    for(int i=1;i<n;i++){
        while(j and s[i]!=s[j]) j=kmp[j-1];
        if(s[i]==s[j]) j++;
        kmp[i]=j;
    }
    return A.size()-kmp[n-1];
}
