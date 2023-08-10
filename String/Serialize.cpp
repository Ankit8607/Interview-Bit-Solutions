// https://www.interviewbit.com/problems/serialize/

string Solution::serialize(vector<string> &A) {
    string ans;
    for(auto i: A){
        ans+=i;
        ans+=to_string(i.size());
        ans+='~';
    }
    return ans;
}
