/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

*/


void rec(int a,int b,int n,int A,vector<string>&ans, string s){
    if(n==0){
        ans.push_back(s);
        return;
    }
    if(a<A) rec(a+1,b,n-1,A,ans,s+"(");
    if(a>b) rec(a,b+1,n-1,A,ans,s+")");
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    string s="";
    rec(0,0,2*A,A,ans,s);
    return ans;
}
