// https://www.interviewbit.com/problems/word-search-board/

/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.

*/


int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool rec(int i,int j,vector<string> &A, string &B,string ans){
    if(ans.size()==B.size()) return true;
    
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 and y>=0 and x<=n-1 and y<=m-1 and (A[x][y]==B[ans.size()]) and rec(x,y,A,B,ans+string(1,A[x][y]))) return true;
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    n=A.size(); m=A[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==B[0] and rec(i,j,A,B,string(1,A[i][j]))) return 1;
        }
    }
    return 0;
}
