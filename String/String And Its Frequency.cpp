// https://www.interviewbit.com/problems/string-and-its-frequency/

string Solution::solve(string A) {
    int arr[26]={0};
    for(int i=0;i<A.size();i++) arr[A[i]-'a']++;
    string ans;
    for(auto i: A){
        if(arr[i-'a']){
            ans+=i+to_string(arr[i-'a']);
            arr[i-'a']=0;
        }
    }
    return ans;
}
