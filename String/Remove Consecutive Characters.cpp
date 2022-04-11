/*

Given a string A and integer B, remove all consecutive same characters that have length exactly B.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= |A|



Input Format
First Argument is string A.

Second argument is integer B.



Output Format
Return a string after doing the removals.



Example Input
Input 1:

A = "aabcd"
B = 2
Input 2:

A = "aabbccd"
B = 2


Example Output
Output 1:

 "bcd"
Output 2:

 "d"


Example Explanation
Explanation 1:

 "aa" had length 2.
Explanation 2:

 "aa", "bb" and "cc" had length of 2.
 
 */
 
 string Solution::solve(string s, int B) {
    string tmp="",var="";
    if(s.size()==0 || B==1) tmp;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(i){
            if(s[i]==s[i-1]) cnt++;
            else{
                tmp+=var;
                var=""; var+=s[i];
                cnt=1;
            }
            if(cnt==B) var="",cnt=0;
        }
        else cnt++,var+=s[i];
    }
    return tmp+var;
}
