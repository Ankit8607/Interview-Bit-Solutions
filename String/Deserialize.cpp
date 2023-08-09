// https://www.interviewbit.com/problems/deserialize/

vector<string> Solution::deserialize(string A) {
    vector<string>ans;
    ans.push_back("");
    for(auto i : A){
        if(i>='a' and i<='z') ans.back()=ans.back()+i;
        if(i=='~') ans.push_back("");
    }
    ans.pop_back();
    return ans;
}
