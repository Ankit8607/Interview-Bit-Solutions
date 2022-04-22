/*

You are given an array of N non-negative integers, A0, A1 ,…, AN-1.

Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/


int mod=1e9+7;
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans=0;
    int n=A.size();
    for(int i=0;i<n-2;i++){
        if(A[i]==0) continue;
        for(int j=i+1;j<n-1;j++){
            int it=lower_bound(A.begin()+j+1,A.end(),A[i]+A[j])-A.begin();
            it--;
            if(it>j)
            ans+=(it-j);
            ans%=mod;
        }
    }
    return ans;
}
