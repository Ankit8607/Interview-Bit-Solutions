// https://leetcode.com/problems/k-similar-strings/

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if(s1==s2) return 0;

        int ans=1e9;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) continue;
            for(int j=i+1;j<s1.size();j++){
                if(s2[i]==s1[j]){
                    swap(s1[i],s1[j]);
                    ans=min(ans,1+kSimilarity(s1,s2));
                    swap(s1[i],s1[j]);
                }
            }
        }
        return ans;
    }
};
