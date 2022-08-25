// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

/*

Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix. 

In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]


*/


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int rows = B.size();
    int cols = B[0].size();

    int max_distance = A;
    vector<vector<int>> cur_distances = B;
    vector<vector<int>> next_distances = cur_distances;

    for (int dist = 0; dist < max_distance; dist++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                int cur = cur_distances[r][c];
                int right = (c == cols - 1) ? -1 : cur_distances[r][c + 1];
                int up = (r == 0) ? -1 : cur_distances[r - 1][c];
                int left = (c == 0) ? -1 : cur_distances[r][c - 1];
                int down = (r == rows - 1) ? -1 : cur_distances[r + 1][c];

                next_distances[r][c] = max({cur, right, up, left, down});
            }
        }

        cur_distances = next_distances;
    }

    return cur_distances;
}
