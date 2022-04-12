/*

Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
    
*/


int Solution::romanToInt(string s) {
    int num[]={0,1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sav[]={"","I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=13;
    int ans=0;
    while(s.size()){
        while(sav[i]==s.substr(0,sav[i].size())){
            ans+=num[i];
            s=s.substr(sav[i].size());
        }
        i--;
    }
    return ans;
}


// Other approach


int Solution::romanToInt(string A) {
     string s=A;
     if (s.empty()) { return 0; }
        unordered_map<char, int> mp { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
}
