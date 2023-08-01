// https://www.interviewbit.com/problems/bulls-and-cows/

string Solution::solve(string A, string B) {
    int x=0,y=0;
    map<char,int>a,b;
    
    for(auto &i: A) a[i]++;
    for(auto &i: B) b[i]++;
    
    for(int i=0;i<A.size();i++) x+=(A[i]==B[i]);
    for(auto i: a) y+=min(i.second,b[i.first]);
    
    string ans=to_string(x)+"A"+to_string(y-x)+"B";
    
    return ans;
}
