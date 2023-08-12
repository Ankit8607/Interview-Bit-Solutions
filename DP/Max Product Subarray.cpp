// https://www.interviewbit.com/problems/max-product-subarray/

int Solution::maxProduct(const vector<int> &A) {
    int ans=-1e9,mx=1,mn=1;
    for(auto i: A){
        if(i==0){
            ans=max(ans,0);
            mx=1;
            mn=1;
        }
        else if(i<0){
            if(mn>0) mx=1,mn=mn*i, ans=max(ans,i);
            else {
                int tmp=mx;
                mx=i*mn;
                ans=max(ans,mx);
                mn=tmp*i;
            }
        }
        else{
            mx=mx*i;
            ans=max(ans,mx);
            mn=mn*i;
        }
    }
    return ans;
}
