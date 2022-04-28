/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

PROBLEM APPROACH :

Complete solution in hints.

*/

int Solution::isValid(string A) {
    stack<char>s;
    for(int i=0;i<A.size();i++){
        if(A[i]==')'){
            if(s.empty() || s.top()!='(') return 0;
            s.pop();
        }
        else if(A[i]=='}'){
            if(s.empty() || s.top()!='{') return 0;
            s.pop();
        }
        else if(A[i]==']'){
            if(s.empty() || s.top()!='[') return 0;
            s.pop();
        }
        else s.push(A[i]);
    }
    return s.empty();
}
