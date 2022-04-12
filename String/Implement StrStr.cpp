/*

Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Problem Description
 
 

Another question which belongs to the category of questions which are intentionally stated vaguely.

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

NOTE: String A is haystack, B is needle.

Good clarification questions:

What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.


*/

int Solution::strStr(const string A, const string B) {
    if(A.size()==0 || B.size()==0) return -1;
    string s=B+"#"+A;
    // cout<<"s= "<<s<<endl;
    int ans[s.size()+1];
    ans[0]=-1;
    int i=0;
    int last=-1;
    // for(int i=0;i<s.size();i++){
    while(i<s.size()){
        while(last!=-1 and s[i]!=s[last])last=ans[last];
        // if(s[i]==s[last]) last++;
        last++; i++;
        ans[i]=last;
    }
    // cout<<"ans= "; for(int i=0;i<s.size();i++) cout<<ans[i]<<" "; cout<<endl;
    int id=-1;
    for(int i=0;i<=s.size();i++){
        if(ans[i]==B.size()){
            id=i;
            break;
        }
    }
    if(id==-1) return -1;
    return id-2*B.size()-1;
}
