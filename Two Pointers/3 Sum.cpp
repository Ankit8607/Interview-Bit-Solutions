/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

Return the sum of the three integers.

Assume that there will only be one solution

Example: 

given array S = {-1 2 1 -4}, 

and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


*/


int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    long long sum;
    // cout<<"A= "; for(auto i:A) cout<<i<<" "; cout<<endl;
    long long ans=1e10,n=A.size();
    // if(n<3) return 0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            long long it=upper_bound(A.begin()+j+1,A.end(),0LL+B-A[i]-A[j])-A.begin();
            if(it!=n){
                long long tmp=abs(0LL+B-A[i]-A[j]-A[it]);
                if(tmp<ans){
                    ans=tmp;
                    sum=0LL+A[i]+A[j]+A[it];
                }
            }
            if(it-1>j){
                long long tmp=abs(0LL+B-A[i]-A[j]-A[it-1]);
                if(tmp<ans){
                    ans=tmp;
                    sum=0LL+A[i]+A[j]+A[it-1];
                }
            }
        }
    }
    return sum;
}
