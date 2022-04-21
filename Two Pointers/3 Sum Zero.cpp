/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:

  (-1, 0, 1)

  (-1, -1, 2)
  
*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>>fin;
    if(A.size()<3) return fin;
    // set<vector<int>> ans;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-2;i++){
        if(i and A[i]==A[i-1]) continue;
        int j=i+1,k=A.size()-1;
        while(j<k){
            if(0LL+A[i]+A[j]+A[k]==0){
                vector<int>res={A[i],A[j],A[k]};
                fin.push_back(res);
                j++;
                while(j<k and A[j-1]==A[j]) j++;
                // k--;
                // while(j<k and A[k]==A[k+1]) k--;
            }
            else if(0LL+A[i]+A[j]+A[k]>0) k--;
            else j++;
        }
    }
    // for(auto i:ans) fin.push_back(i);
    return fin;
}
