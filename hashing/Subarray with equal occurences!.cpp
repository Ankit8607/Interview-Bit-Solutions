// https://www.interviewbit.com/problems/subarray-with-equal-occurences/

int Solution::solve(vector<int> &A, int B, int C) {
    map<int,int>mp;
    int sum=0;
    for(auto i:A){
        if(i==B) sum++;
        if(i==C) sum--;
        mp[sum]++;
    }
    sum=0;
    int ans=0;
    for(auto i: A){
        ans+=mp[sum];
        if(i==B) sum++;
        if(i==C) sum--;
        mp[sum]--;
    }
    return ans;
}
