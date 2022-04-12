/*

Given two binary strings, return their sum (also a binary string).
Example:

a = "100"


b = "11"
Return a + b = "111".

*/

string Solution::addBinary(string A, string B) {
    int carry=0;
    string ans="";
    int a=A.size(),b=B.size();
    a--; b--;
    while(a>=0 || b>=0){
        int tmp=carry;
        if(a>=0) tmp+=A[a]-'0';
        if(b>=0) tmp+=B[b]-'0';
        // cout<<"tmp= "<<tmp<<" ";
        if(tmp%2){
            if(tmp==1) carry=0;
            else carry=1;
            ans+='1';
        }
        else{
            ans+='0';
            if(tmp==2) carry=1;
            else carry=0;
        }
        // cout<<"carry= "<<carry<<endl;
        a--; b--;
    }
    if(carry) ans+='1';
    reverse(ans.begin(),ans.end());
    int i=0;
    while(ans[i]=='0') i++;
    ans.erase(ans.begin(),ans.begin()+i);
    return ans;
}
