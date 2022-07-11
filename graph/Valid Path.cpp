// https://www.interviewbit.com/problems/valid-path/

/*

There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.




Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
Constraints

0 <= x, y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid
For Example

Input:
    x = 2
    y = 3
    N = 1
    R = 1
    A = [2]
    B = [3]
Output:
    NO
   
Explanation:
    There is NO valid path in this case
    
*/


int dx[8]={1,1,0,-1,0,-1,-1,1};
int dy[8]={1,0,1,0,-1,-1,1,-1};

bool isvalid(int x, int y, int r, vector<int> &E, vector<int> &F){

    for(int i=0;i<E.size();i++){
        int x1=E[i],y1=F[i];
        if( (x-x1)*(x-x1) + (y-y1)*(y-y1) <= r*r ){
            return 0;
        }
    }
    return 1;
}


bool dfs(int i, int j, int A, int B, int C, int D, vector<int> &E, vector<int> &F, vector<vector<bool>> &visited)
{
    if(i==A && j==B && isvalid(i,j,D,E,F))
        return true;

    if(i>=0 && j>=0  && i<=A && j<=B && isvalid(i,j,D,E,F) && visited[i][j]==0)
    {
        visited[i][j]=1;
        for(int k=0;k<8;k++)
        {
            bool check=dfs(i+dx[k],j+dy[k],A,B,C,D,E,F,visited);
            if(check)
                return true;
        }
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
   
    vector<vector<bool>> visited(A+1,vector<bool>(B+1,0));
    bool check=dfs(0,0,A,B,C,D,E,F,visited);
   
    if(check)
        return "YES";
    return "NO";
}
