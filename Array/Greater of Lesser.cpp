// https://www.interviewbit.com/problems/greater-of-lesser/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int a=0,b=0;
    for(auto i:A) if(i>C) a++;
    for(auto i:B) if(i<C) b++;
    return max(a,b);
}
