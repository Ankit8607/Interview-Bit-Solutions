// https://www.interviewbit.com/problems/palindromic-substrings/

int Solution::solve(string A) {
    int ans=0,n=A.size();
    for(int i=0;i<A.size();i++){
        int l=i,r=i;
        while(l>=0 and r<n){
            if(A[l]==A[r]) ans++;
            else break;
            l--; r++;
        }
        l=i; r=i+1;
        while(l>=0 and r<n){
            if(A[l]==A[r]) ans++;
            else break;
            l--; r++;
        }
    }
    return ans;
}
