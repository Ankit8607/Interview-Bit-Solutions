/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]

*/


First Approach

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>>ans(2*n-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i+j].push_back(A[i][j]);
            // cout<<ans[i+j][0]<<" ";
        }
    }
    return ans;
}

Second Approach

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int x=A.size();
    vector<vector<int> >res(2*x-1);
    int count=0;
    for(int i=0;i<x;i++){
        int a=0,y=i;
        while(a<x&&y>=0){
            res[count].push_back(A[a][y]);
            a++;
            y--;
        }
        count++;
    }
    for(int i=1;i<x;i++){
        int a=i,y=x-1;
        while(a<x&&y>=0){
            res[count].push_back(A[a][y]);
            a++;
            y--;
        }
        count++;
    }
    return res;
}
