// https://www.interviewbit.com/problems/all-factors/

vector<int> Solution::allFactors(int A) {
    vector<int>ans;
    for(int i=1;i<=sqrt(A);i++){
        if(A%i==0){
            int a=A/i;
            ans.push_back(i);
            if(a!=i) ans.push_back(a);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
