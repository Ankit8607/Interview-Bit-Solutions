// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0) return 0;
    int n=A.size(),m=A[0].size();
    vector<vector<int>>row(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            row[i+1][j+1]=A[i][j]+row[i+1][j];
    
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            map<int,int>mp; mp[0]=1;
            int sum=0;
            for(int k=1;k<=n;k++){
                sum+=row[k][j]-row[k][i-1];
                ans+=mp[sum];
                mp[sum]++;
            }
        }
    }
    return ans;
}
