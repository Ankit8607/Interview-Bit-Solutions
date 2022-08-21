// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

/*

How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?

Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 

*/


int Solution::fibsum(int A) {
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    while(arr.back()<=A){
        int n=arr.size();
        arr.push_back(arr[n-1]+arr[n-2]);
    }
    int ans=0;
    while(A){
        int it=upper_bound(arr.begin(),arr.end(),A)-arr.begin();
        it--;
        A-=arr[it];
        ans++;
    }
    return ans;
}
