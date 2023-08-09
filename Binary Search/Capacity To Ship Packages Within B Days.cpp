// https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/

bool check(int mid,vector<int>&arr,int days){
    int cnt=0,sum=0;
    for(auto i: arr){
        sum+=i;
        if(sum>mid){
            sum=i;
            cnt++;
        }
    }
    cnt++;
    return cnt<=days;
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int lo=*max_element(A.begin(),A.end()),hi=0,ans=0;
    for(auto i: A) hi+=i;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid,A,B)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
    }
    return ans;
}
