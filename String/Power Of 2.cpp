/*

Find if Given number is power of 2 or not. 

More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1

*/


int Solution::power(string s){ 
    int n=s.size();
    while(1){
        int carry=0;
        for(int i=0;i<n;i++){
            int t=s[i]-'0';
            t+=carry*10;
            carry=t%2;
            s[i]=t/2+'0';
        }
        if(carry) return 0;
        // cout<<"s[n-1]= "<<s[n-1]<<" ";
        for(int i=0;i<n;i++){
            if(i==(n-1) and (s[i]=='1'||s[i]=='2')) return 1;
            else if(s[i]!='0') break;
        }
    }
    return 1;
}
