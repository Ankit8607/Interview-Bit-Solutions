// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &A)
{
    vector<int>left(A.size()),right(A.size());
    int min_price=INT_MAX,max_price=INT_MIN,ans=0,profit=0;
    for(int i=0;i<A.size();i++)
    {
        min_price=min(min_price,A[i]);
        left[i]=max(profit,A[i]-min_price);
        profit=max(profit,left[i]);
    }
    profit=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        max_price=max(max_price,A[i]);
        right[i]=max(profit,max_price-A[i]);
        profit=max(profit,right[i]);
    }
    for(int i=0;i<A.size();i++)
    {
        ans=max(ans,right[i]+left[i]);
    }
    return ans;
}
