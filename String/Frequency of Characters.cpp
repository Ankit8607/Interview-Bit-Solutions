// https://www.interviewbit.com/problems/frequency-of-characters/

vector<int> Solution::solve(string A) {
    vector<int>ans(26,0);
    for(auto i:A) ans[i-'a']++;
    return ans;
}
