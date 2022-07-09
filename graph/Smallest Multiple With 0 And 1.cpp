// https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/

/*

You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. Since this multiple could be large, return it in form of a string.

Note:

Returned string should not contain leading zeroes.
For example,

For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
For N = 2, 10 is the answer.

*/


string Solution::multiple(int A) {
    if(A==1) return "1";
    queue<int>q;
    q.push(1);
    vector<int>par(A,0);
    par[1]=-1;
    while(!q.empty()){
        int rem=q.front(); q.pop();
        if(rem==0) break;
        if(!par[rem*10%A])
            par[rem*10%A]=rem,
            q.push(rem*10%A);
        if(!par[(rem*10+1)%A])
            par[(rem*10+1)%A]=rem,
            q.push((rem*10+1)%A);
    }
    string ans="";
    int rem=0;
    while(rem!=-1){
        if((10*par[rem])%A==rem) ans+='0';
        else ans+='1';
        rem=par[rem];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
