/*

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. 

Look at the example for more details.

Example :

Input : 'aba'
Output : 2

The order permutations with letters 'a', 'a', and 'b' : 
aab
aba
baa

*/


int mod=1000003;
#define mx 256

int power(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return ans;
}

void fun(int fact[],int n){
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=(1LL*fact[i-1]*i)%mod;
}
int Solution::findRank(string s) {
    int n=s.size();
    int freq[mx]={0};
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    int fact[n+1];
    fun(fact,n);
    int ans=0;
    int mul=fact[n-1];
    for(int i=0;i<mx;i++){
        mul=(1LL*mul*power(fact[freq[i]],mod-2))%mod;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<(int)s[i];j++){
            if(freq[j]){
                ans+=(1LL*mul*freq[j])%mod;
            }
        }
        mul=(1LL*mul*power(n-i-1,mod-2))%mod;
        mul=(1LL*mul*freq[s[i]]);
        freq[s[i]]--;
        ans%=mod;
    }
    return ans+1;
}
