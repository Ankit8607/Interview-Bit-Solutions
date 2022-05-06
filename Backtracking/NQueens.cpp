/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

N Queens: Example 1

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/



bool check(int row ,int col,vector<int> &que){
    for(int prow=0;prow<row;prow++){
        int pcol=que[prow];
        if(pcol==col || (abs(prow-row)==abs(pcol-col))) return 0;
    }
    return 1;
}

void rec(int level, int A, vector<vector<string>> &ans, vector<int>&que){
    if(level==A){
        vector<string> tmp(A,(string(A,'.')));
        for(int i=0;i<A;i++){
            tmp[i][que[i]]='Q';
        }
        ans.push_back(tmp);
        return;
    }

    for(int col=0;col<A;col++){
        if(check(level,col,que)){
            que.push_back(col);
            rec(level+1,A,ans,que);
            que.pop_back();
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<int> que;
    vector<vector<string>> ans;
    rec(0, A, ans,que);
    return ans;
}
