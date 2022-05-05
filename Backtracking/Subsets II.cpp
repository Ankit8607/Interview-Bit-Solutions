/*

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :

If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

*/



void rec(int level,vector<pair<int,int>> &A, vector<vector<int>> &ans, vector<int>&v){
    ans.push_back(v);
    for(int i=level;i<A.size();i++){
        v.push_back(A[i].first);
        A[i].second--;
        if(A[i].second)( rec(i,A,ans,v));
        else rec(i+1,A,ans,v);
        v.pop_back();
        A[i].second++;
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector<vector<int>>ans;
    if(A.size()==0){ 
        ans.push_back({});
        return ans;
    }
    sort(A.begin(),A.end());
    vector<pair<int,int>>pr;
    pr.push_back({A[0],1});
    for(int i=1;i<A.size();i++){
        if(A[i]==A[i-1]){
            pr[pr.size()-1].second++;
        }
        else pr.push_back({A[i],1});
    }
    vector<int>v;
    rec(0,pr,ans,v);
    return ans;
}
