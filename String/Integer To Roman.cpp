/*

Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.




Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
    
 */


//Mine approach


#define endl "\n"
#define F first
#define S second
string ans="";
vector<pair<int,char>>v;
void fun1(int i,int &x){
    if(x/v[i].F>3){
        ans+=v[i].S;
        ans+=v[i+1].S;
        x-=(v[i+1].F-v[i].F);
    }
    else{
        int t=x/v[i].F;
        while(t--){
            ans+=v[i].S;
            x-=v[i].F;
        }
    }
}
void fun2(int i,int &x){
    int diff=v[i+1].F-v[i-1].F;
    if(diff<=x){
        ans+=v[i-1].S;
        ans+=v[i+1].S;
        x-=(v[i+1].F-v[i-1].F);
    }
    else{
        ans+=v[i].S;
        x-=v[i].F;
    }
}

string Solution::intToRoman(int x) {
    ans="";
    v.resize(7);
    v[0]={1,'I'}; v[1]={5,'V'}; v[2]={10,'X'}; v[3]={50,'L'};
    v[4]={100,'C'}; v[5]={500,'D'}; v[6]={1000,'M'};
    while(x!=0){
        int i=6;
        while(x/v[i].F==0) i--;
        // string ch5or10=to_string(v[i].F);
        // while(ch5or10%10==0) ch5or10/=10;
        if(to_string(v[i].F)[0]=='1'){
            fun1(i,x);
        }
        else fun2(i,x);
    }
    return ans;
}




// interview bit approach


string Solution::intToRoman(int A) {
    string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[A/1000] + C[(A%1000)/100] + X[(A%100)/10] + I[A%10];
}
