// https://www.interviewbit.com/problems/salutes/

long Solution::countSalutes(string A) {
    long long ans=0;
    int cnt=0;
    for(auto i:A){
        if(i=='>') cnt++;
        else ans+=cnt;
    }
    return ans;
}
