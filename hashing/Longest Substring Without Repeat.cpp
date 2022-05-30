// https://www.interviewbit.com/problems/longest-substring-without-repeat/

/*

Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/


int Solution::lengthOfLongestSubstring(string A) {
    int cnt=0;
    map<char,int>mp;
    int ans=0,last=0;
    for(int i=0;i<A.size();i++){
        if(mp[A[i]]==1) cnt++;
        mp[A[i]]++;
        while(cnt!=0){
            if(mp[A[last]]==2) cnt--;
            mp[A[last]]--;
            last++;
        }
        ans=max(ans,i-last+1);
    }
    return ans;
}
