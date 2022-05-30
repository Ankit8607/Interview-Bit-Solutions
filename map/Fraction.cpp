// https://www.interviewbit.com/problems/fraction/

/*

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"

*/


string Solution::fractionToDecimal(int A, int B) {
    long long a=A,b=B;
    if(a==0) return "0";
    if(a%b==0) return to_string(a/b);
    int is_neg=(a*b/abs(a))/abs(b);
    string ans="";
    if(is_neg==-1) ans="-";
    a=abs(a); b=abs(b);
    ans+=to_string(a/b)+".";
    a=a%b;

    map<int,int>mp;
    while(a){
        if(mp[a]){
            ans.insert(mp[a],1,'(');
            ans+=")";
            return ans;
        }
        mp[a]=ans.size();
        ans+=to_string((a*10)/b);
        a=(a*10)%b;
    }
    return ans;
}

