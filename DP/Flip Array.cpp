// https://www.interviewbit.com/problems/flip-array/

/*

Given an array of  positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum

*/


int Solution::solve(const vector<int> &A) {
    int sum=0,n=A.size();
    for(auto i:A) sum+=i;
    int pos[n][sum+1];
    int neg[n][sum+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            pos[i][j]=1e9;
            neg[i][j]=1e9;
        }
    }
    pos[0][A[0]]=0;
    neg[0][A[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(pos[i-1][j]!=1e9){
                pos[i][j+A[i]]=min(pos[i-1][j],pos[i][j+A[i]]);
                if(j-A[i]<0) neg[i][abs(j-A[i])]=min(neg[i][abs(j-A[i])],pos[i-1][j]+1);
                else pos[i][j-A[i]]=min(pos[i][j-A[i]],1+pos[i-1][j]);
            }
            if(neg[i-1][j]!=1e9){
                neg[i][j+A[i]]=min(1+neg[i-1][j],neg[i][j+A[i]]);
                if(A[i]-j>=0) pos[i][A[i]-j]=min(pos[i][A[i]-j],neg[i-1][j]);
                else neg[i][j-A[i]]=min(neg[i][j-A[i]],neg[i-1][j]);
            }
        }
    }
    for(int i=0;i<=sum;i++){
        if(pos[n-1][i]!=1e9) return pos[n-1][i];
    }
}
