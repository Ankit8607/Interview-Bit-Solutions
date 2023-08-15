// https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n=a.size();
    vector<int>arr(n,n-1);
    vector<int>brr(n,n-1);
    
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    arr[n-1]--;
    brr[n-1]--;
    vector<int>ans;
    while(c--){
        int sum=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        ans.push_back(sum);
        if(j>0 and brr[j-1]>=i and arr[i]>=j-1){
            pq.push({a[i]+b[j-1],{i,j-1}});
            brr[j-1]=i-1;
            arr[i]=j-2;
        }
        if(i>0 and arr[i-1]>=j and brr[j]>=i-1){
            pq.push({b[j]+a[i-1],{i-1,j}});
            arr[i-1]=j-1;
            brr[j]=i-2;
        }
    }
    return ans;
}
