// https://www.interviewbit.com/problems/maximum-edge-removal/

/*

Problem Description

Given an undirected tree with an even number of nodes. Consider each connection between a parent and child node to be an edge.

You need to remove maximum number of these edges, such that the disconnected subtrees that remain each have an even number of nodes.

Return the maximum number of edges you can remove.



Problem Constraints
2 <= A <= 105

1 <= B[i][0], B[i][1] <= A

Integer A will be even.



Input Format
First argument is an integer A denoting the number of nodes in the tree.

Second argument is a 2D array B of size (A-1) * 2, denoting the edge between nodes B[i][0] and B[i][1].



Output Format
Return an integer, denoting the maximum number of edges you can remove.



Example Input
Input 1:

 A = 6
 B = [
       [1, 2]
       [1, 3]
       [1, 4]
       [3, 5]
       [4, 6]
     ]
Input 2:

 A = 2
 B = [
       [1, 2]
     ]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

      1
    / | \
   2  3  4
      |   \
      5    6
 Maximum number of edges we can remove is 2, i.e (1, 3) and (1, 4)
Explanation 2:

 We can't remove any edges.
 
 */


vector<int>vis;
int ans=0;
int dfs(int node,vector<vector<int>>&g){
    vis[node]=1;
    int sub=0;
    for(auto v:g[node]){
        if(!vis[v]){
            int tmp=dfs(v,g);
            if(tmp%2==0) ans++;
            else sub+=tmp; 
        }
    }
    return sub+1;
}

int Solution::solve(int n, vector<vector<int> > &B) {
    vector<vector<int>>g(n+1);
    ans=0;
    for(auto i:B){
        g[i[0]].push_back(i[1]);
        g[i[1]].push_back(i[0]);
    }
    vis.resize(n+1);
    for(int i=1;i<=n;i++)vis[i]=0;
    dfs(1,g);
    return ans;
}
