// https://www.interviewbit.com/problems/integers-in-strings/

vector<int> Solution::solve(string A) {
    vector<int>ans;
    ans.push_back(0);
    for(auto i: A){
        if(i==',') ans.push_back(0);
        else ans.back()=ans.back()*10+(i-'0');
    }
    return ans;
}
