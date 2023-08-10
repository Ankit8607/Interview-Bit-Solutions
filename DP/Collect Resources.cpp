// https://www.interviewbit.com/problems/collect-resources/

int Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {

    long long sum = 0;

    

    int n=A.size(), m=A[0].size();

    vector<long long>dp(m+1,0);


    dp[0]=0;

    for(int i=0;i<n;i++)

    {

        long long s=0;

        for(int j=0;j<m;j++)

        {

            sum+=A[i][j];

            B[i][j]-=A[i][j];

            s+=B[i][j];

            //Whenever u install a LR pipeline , just take max elements u could transfer with that length of pipeline

            dp[j+1] = max(dp[j],s+dp[j+1]);

        }

    }

    int mod = 1e9+7;

    return (sum+dp[m])%mod;

}
