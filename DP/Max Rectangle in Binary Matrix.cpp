// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int fun(vector<int>&A){
    stack<int>l,r;
    int ind=0,n=A.size();
    int left[n],right[n];
    
    for(int i=0;i<n;i++){
        while(!l.empty() and A[l.top()]>=A[i]) l.pop();
        if(l.empty()) left[i]=-1;
        else left[i]=l.top();
        l.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(!r.empty() and A[r.top()]>=A[i]) r.pop();
        if(r.empty()) right[i]=n;
        else right[i]=r.top();
        r.push(i);
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,1LL*(right[i]-left[i]-1)*A[i]);
    }
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &arr) {
    const int n = arr.size(), m = arr[0].size();
    
    vector<int> height(m,0);
    int ans = 0;
    for ( int row = 0;row < n;row++)
    {
        for ( int i = 0;i<m;i++){
            if ( arr[row][i] == 1)  height[i] += 1;
            else  height[i] = 0;
        }
        ans=max(ans,fun(height));
    }
    return ans;
}
