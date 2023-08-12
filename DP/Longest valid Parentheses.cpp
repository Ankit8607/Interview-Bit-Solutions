// https://www.interviewbit.com/problems/longest-valid-parentheses/

int Solution::longestValidParentheses(string s) { 
    const int n = s.size();
    vector<int> dp(n, 0);
    int ans = 0;
    for (int i=1;i<n;i++)
    {
        if (s[i] == ')') {
            if ( (i - dp[i-1] - 1) >= 0 and s[i - dp[i-1] - 1] == '(') {
                // dp[i] += dp[i-1] + 2 + dp[i - dp[i-1] - 2]; 
                dp[i] = (i -2 - dp[i-1]) >= 0 ? dp[i-1] + 2 + dp[i - dp[i-1] - 2] : dp[i-1] + 2;
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}
