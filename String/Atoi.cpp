/*

There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions:

Q1. Does string contain whitespace characters before the number?

A. Yes

Q2. Can the string have garbage characters after the number?

A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do?

A. Return 0.

Q4. What if the integer overflows?

A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/


// Smart way

int Solution::atoi(const string A) {
stringstream ss;
ss<<A;
long long i;
ss>>i;
if(i<INT_MIN)
i=INT_MIN;
if(i>INT_MAX)
i=INT_MAX;
return i;
}


// Other Approach


int Solution::atoi(const string A) {
    int ans=0,neg=1;
    for(int i=0;i<A.size();i++){
        if(A[i]=='-') neg=-1;
        else if(A[i]=='+') continue;
        else if(A[i]<'0' || A[i]>'9') return ans*neg;
        else {
            if((1LL*ans*10+(A[i]-'0'))>INT_MAX){
                if(neg==1) return INT_MAX;
                return INT_MIN;
            }
            ans=(ans*10)+(A[i]-'0');
        }
    }
    return ans*neg;
}
