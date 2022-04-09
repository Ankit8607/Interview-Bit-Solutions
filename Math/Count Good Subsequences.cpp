/*

An array is good if all the elements present in it have the same frequency. For example, [2, 3, 3, 2] is good because both 2 and 3 have frequency 2. [2, 3, 2] is not good because the frequencies of 2 and 3 are 2 and 1 respectively. You are given an array A. You need to count the number of non-empty good subsequences of A. Since the answer can be large, return it modulo 109+7.



Problem Constraints
1 <= |A| <= 200000

1 <= A[i] <= 109



Input Format
First argument is an integer array A.



Output Format
Return the number of good subsequences modulo 109+7.



Example Input

  Input 1:

  A = [1, 2, 1] 

  Input 2:

  A = [5, 10, 2] 


Example Output

  Output 1:

  6

  Output 2:

  7


Example Explanation

  Explanation 1:

 
  Let's denote a subsequence by its set of indices and assume array to be 0 indexed. Then the following subsequences are good- 
  {0}, {1}, {2}, {0, 1}, {1, 2}, {0, 2}.

  Explanation 2:



  All the subsequences are good. So there are 23 - 1 = 7 subsequences.
  
  */

const int M = 1e9 + 7;
int expo(int a, int b, int mod){
    int ans = 1;
    while(b){
        if(b&1)
            ans = (ans * 1LL * a)%mod;
        a = (a * 1LL * a)%mod;
        b >>= 1;
    }
    return ans;
}
const int N=500005;
int f[N], inv[N];
void preprocess()
{
    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = (i* 1LL *f[i-1])%M;
    inv[N-1] = expo(f[N-1],M-2,M);
    for(int i = N-2; i >= 0; i--)
        inv[i] = ((i+1) * 1LL * inv[i+1])%M;
}
int C(int n,int r){
	if(r>n)
		return 0;
    return (((f[n] * 1LL * inv[r])%M) * 1LL * inv[n-r])%M;
}
int Solution::solve(vector<int> &A) {
    preprocess();
    map<int,int>m;
    for(auto i:A)
        m[i]++;
    vector<int>v;
    for(auto i:m)
        v.push_back(i.second);
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<=v.back();i++){
        int res = 1;
        for(auto it=lower_bound(v.begin(),v.end(),i); it != v.end(); it++)
            res=(res * 1LL * (1+C(*it,i)))%M;
        ans=(ans+res-1)%M;
    }
    return ans;
}
