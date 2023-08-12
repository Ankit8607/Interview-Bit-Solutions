// https://www.interviewbit.com/problems/palindrome-numbers/

bool palin(string a){
    int n=a.size();
    int l=0,r=n-1;
    while(l<r) if(a[l++]!=a[r--]) return 0;
    return 1;
}

int Solution::solve(int A, int B, int C) {
    deque<int>q;
    int ans=0;
    for(int i=A;i<=B;i++){
        if(palin(to_string(i))) q.push_front(i);
        if(!q.empty() and i-q.back()>C) q.pop_back();
        ans=max(ans,(int)q.size());
    }
    return ans;
}
