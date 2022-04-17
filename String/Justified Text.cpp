/*

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified. You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ' ' when necessary so that each line has exactly L characters. Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]


L: 16.



Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length. 

*/


vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string>ans;
    int n=A.size();
    string s;
    int len=0,words=0,i=0;
    while(i<n){
        len=0;words=0; s="";
        int l=i;
        while(i<n and len+A[i].size()<=B){
            len+=A[i].size()+1;
            words+=A[i].size();
            i++;
        }
        if((i-l)==1){
            s+=A[i-1]+string(B-A[i-1].size(),' ');
            ans.push_back(s);
            continue;
        }
        if(i==n){
            while(l<n){
                s+=A[l++];
                if(l!=n) s+=' ';
            }
            while(s.size()<B) s+=' ';
            ans.push_back(s);
            continue;
        }
        int extraspace=B-words;
        int put=extraspace/(i-l-1);
        int till=extraspace%(i-l-1);
        while(till--){
            s+=A[l++];
            s+=string(put+1,' ');
        }
        while(i>l){
            s+=A[l++];
            if(l!=i)
            s+=string(put,' ');
        }
        ans.push_back(s);
    }
    return ans;
}
