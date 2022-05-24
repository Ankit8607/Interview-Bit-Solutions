// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

/*

Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.

*/


vector<int> Solution::lszero(vector<int> &A) {
    int n=A.size();
    map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    int l=0,r=-1;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(mp.find(sum)!=mp.end()){
            if(r-l<i-mp[sum]-1){
                r=i;
                l=mp[sum]+1;
            }
        }
        else{
            mp[sum]=i;
        }
    }
    vector<int>ans;
    if(r>=0){
        for(int i=l;i<=r;i++) ans.push_back(A[i]);
    }
    return ans;
}
