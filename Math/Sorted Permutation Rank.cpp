/*

Given a string, find the rank of the string amongst its permutations sorted lexicographically. 

Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

*/

int mod=1000003;
#define mx 256

void fun(int fact[],int n){
    fact[0]=1;
    for(int i=1;i<=n;i++) fact[i]=(1LL*fact[i-1]*i)%mod;
}
int Solution::findRank(string s) {
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n=s.size();
    int freq[mx]={0};
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    int pre[mx];
    pre[0]=freq[0];
    for(int i=1;i<mx;i++) pre[i]=pre[i-1]+freq[i];
    int fact[n+1];
    fun(fact,n);
    int ans=0;
    for(int i=0;i<n;i++){
        int less=pre[s[i]]-freq[s[i]];
        // cout<<"less= "<<less<<" ";
        ans+=(1LL*less*fact[n-i-1])%mod;
        ans%=mod;
        freq[s[i]]--;
        for(int j=s[i];j<mx;j++){
            pre[j]--;
        }
        ans%=mod;
        // cout<<"ans= "<<ans<<endl;
    }
    return ans+1;
}
