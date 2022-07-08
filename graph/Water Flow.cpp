// https://www.interviewbit.com/problems/water-flow/

/*

Problem Description

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format
First and only argument is a 2D matrix A.



Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.



Example Input
Input 1:

 A = [
       [1, 2, 2, 3, 5]
       [3, 2, 3, 4, 4]
       [2, 4, 5, 3, 1]
       [6, 7, 1, 4, 5]
       [5, 1, 1, 2, 4]
     ]
Input 2:

 A = [
       [2, 2]
       [2, 2]
     ]


Example Output
Output 1:

 7
Output 2:

 4


Example Explanation
Explanation 1:

 Blue Lake ~   ~   ~   ~   ~ 
        ~  1   2   2   3  (5) *
        ~  3   2   3  (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (5)  1   1   2   4  *
           *   *   *   *   * Red Lake
 Water can flow to both lakes from the cells denoted in parentheses.

Explanation 2:

 Water can flow from all cells.
 
 */
 
 
 
 void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& vis,vector<vector<int>>& A,int n,int m)
{
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = dx[i]+p.first;
            int y = dy[i]+p.second;
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y] == false && A[p.first][p.second] <= A[x][y])
            {
                q.push({x,y});
                vis[x][y] = true;
            }
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if(n == 0)
        return 0;
    int m = A[0].size();
    vector<vector<bool>> red(n,vector<bool>(m,false));
    vector<vector<bool>> blue(n,vector<bool>(m,false));
    queue<pair<int,int>> q1,q2;
    for(int i=0;i<n;i++)
    {
        q1.push({i,0});
        red[i][0] = true;
        q2.push({i,m-1});
        blue[i][m-1] = true;
    }
    for(int i=0;i<m;i++)
    {
        q1.push({0,i});
        red[0][i] = true;
        q2.push({n-1,i});
        blue[n-1][i] = true;
    }
    bfs(q1,red,A,n,m);
    bfs(q2,blue,A,n,m);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(red[i][j] && blue[i][j])
                ans++;
        }
    }
    return ans;
}
