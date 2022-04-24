/*

You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :

max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 
         
*/


int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int ans=1e9;
    int n=B.size();
    int i=0,j=0,k=0;
    // for(int i=0;i<n;i++){
        // int it=upper_bound(A.begin(),A.end(),B[i])-A.begin();
        // int tmp=1e9;
        // if(it<A.size()) tmp=abs(A[it]-B[i]);
        // if(it>0) tmp=min(tmp,abs(A[it-1]-B[i]));
        // it=upper_bound(C.begin(),C.end(),B[i])-C.begin();
        // int tmp2=1e9;
        // if(it<C.size()) tmp2=abs(C[it]-B[i]);
        // if(it>0) tmp=min(tmp,abs(C[it-1]-B[i]));
        // int res=max(tmp,tmp2);
        // if(res<=abs())
    // }
    while(j<n){
        while(i<A.size()-1 and A[i]<B[j]){
            i++;
        }
        while(k<C.size()-1 and C[k]<B[j]){
            k++;
        }
        int tmp=1e9;
        if(i>0 and k>0) tmp=min(tmp,max(abs(A[i-1]-B[j]),max(abs(C[k-1]-B[j]),abs(A[i-1]-C[k-1]))));
        if(i>0) tmp=min(tmp,max(abs(A[i-1]-B[j]),max(abs(C[k]-B[j]),abs(A[i-1]-C[k]))));
        if(j>0) tmp=min(tmp,max(abs(A[i]-B[j]),max(abs(C[k-1]-B[j]),abs(A[i]-C[k-1]))));
        tmp=min(tmp,max(abs(A[i]-B[j]),max(abs(C[k]-B[j]),abs(A[i]-C[k]))));
        ans=min(ans,tmp);
        j++;
    }
    return ans;
}


//  Smart approach

int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
  int diff = INT_MAX;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int i=0, j=0, k=0;
        while(i < a.size() && j < b.size() && k < c.size()) {
            minimum = min(a[i], min(b[j], c[k]));
            maximum = max(a[i], max(b[j], c[k]));
            diff = min(diff, maximum - minimum);
            if (diff == 0) break;
            if (a[i] == minimum) i++;
            else if (b[j] == minimum) j++;
            else k++;
        }
        return diff;
}
