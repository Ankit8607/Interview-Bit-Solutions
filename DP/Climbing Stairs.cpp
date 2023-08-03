// https://www.interviewbit.com/problems/climbing-stairs/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int arr[n][2];
    arr[n-1][1]=A[n-1];
    arr[n-1][0]=A[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i][0]=A[i]+min(arr[i+1][0],arr[i+1][1]);
        if(i<n-2) arr[i][1]=A[i]+min(arr[i+2][0],arr[i+2][1]);
        else arr[i][1]=arr[i][0];
    }
    if(n==2) return A[0]+A[1];
    return min(arr[0][0],arr[0][1]);
}
