// https://www.interviewbit.com/problems/self-permutation/

int Solution::minSmoke(vector < int > & A) {
    
    int n = A.size();
    assert(n>=1 && n<=100);
    
    for(auto i:A) assert(i>=0 && i < 100);
    long sum[n][n], dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        sum[i][i] = A[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            long min = 1 << 30;
            for (int k = i; k <= j - 1; k++) {
                long temp = dp[i][k] + dp[k + 1][j] + (sum[i][k] * sum[k + 1][j]);
                if (temp < min) {
                    sum[i][j] = (sum[i][k] + sum[k + 1][j]) % 100;
                    min = temp;
                    dp[i][j] = min;
                }
            }
        }
    }
    return (int) dp[0][n - 1];
}
