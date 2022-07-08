// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

/*
Problem Description

Given an arbitrary unweighted rooted tree which consists of N nodes.

The goal of the problem is to find largest distance between two nodes in a tree.

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints
1 <= N <= 40000



Input Format
First and only argument is an integer array A of size N.



Output Format
Return a single integer denoting the largest distance between two nodes in a tree.



Example Input
Input 1:

 A = [-1, 0, 0, 0, 3]


Example Output
Output 1:

 3


Example Explanation
Explanation 1:

 node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4

 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3.
 
 */


int ans,leaf;
void dfs(int node,int par,vector<vector<int>>&g,int dep){
    for(auto v:g[node]){
        if(v!=par) dfs(v,node,g,dep+1);
    }
    if(g[node].size()==1){
        if(dep>ans){
            ans=dep;
            leaf=node;
        }
    }
}

int Solution::solve(vector<int> &A) {
    ans=0;leaf=0;
    vector<vector<int>>g(A.size());
    for(int i=0;i<A.size();i++){
        if(A[i]!=-1) g[i].push_back(A[i]),g[A[i]].push_back(i);
    }
    dfs(0,-1,g,0);
    dfs(leaf,-1,g,0);
    return ans;
}
