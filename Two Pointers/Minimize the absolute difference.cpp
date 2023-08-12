// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int ans=1e9,i=0,j=0,k=0;
    int n=A.size(),m=B.size(),o=C.size();
    while(i<n and j<m and k<o){
        ans=min(ans,max({A[i],B[j],C[k]})-min({A[i],B[j],C[k]}));
        if(A[i]<B[j]){
            if(A[i]<C[k]) i++;
            else k++;
        }
        else if(A[i]<C[k]){
            if(A[i]<B[j]) i++;
            else j++;
        }
        else{
            if(B[j]>C[k]) k++;
            else j++;
        }
    }
    return ans;
}
