// https://www.interviewbit.com/problems/window-string/

/*


Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

*/


string Solution::minWindow(string A, string B) {
    int diffinb=0;
    map<char,int>cntb;
    for(auto i:B){
        cntb[i]++;
        if(cntb[i]==1) diffinb++;
    }
    map<char,int>cnta;
    int l=0,r=1e9,last=0;
    int j=0;
    for(auto i:A){
        cnta[i]++;
        if(cnta[i]==cntb[i]) diffinb--;
        while(diffinb==0){
            if(r-l>j-last) r=j,l=last;
            cnta[A[last]]--;
            if(cnta[A[last]]<cntb[A[last]]) diffinb++;
            last++;
        }
        j++;
    }
    if(r==1e9) return "";
    string s="";
    for(int i=l;i<=r;i++) s+=A[i];
    return s;
}
