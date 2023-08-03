// https://www.interviewbit.com/problems/word-count/

int Solution::solve(string A) {
    int cnt=0,n=A.size();
    int i=0;
    while(i<n){
        if(A[i]==' ' and i!=0) cnt++;
        while(A[i]==' ') i++;
        i++;
    }
    if(A[n-1]==' ') cnt--;
    return cnt+1;
}
