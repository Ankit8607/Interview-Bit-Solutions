/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",


return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.



*/

int Solution::lengthOfLastWord(const string A) {
    int cnt=0;
    // int t=A.size()-1;
    // while(A[t]==' ') t--;
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]==' ' and cnt==0) continue;
        if(A[i]==' ') return cnt;
        else cnt++;
    }
    return cnt;
}
