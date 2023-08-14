// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &A) {
    if(A.size()<2) return 0;
    int ans=0,mn=A[0];
    for(auto i:A){
        ans=max(ans,i-mn);
        mn=min(mn,i);
    }
    return ans;
}
