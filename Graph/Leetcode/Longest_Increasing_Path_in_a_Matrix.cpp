#include<bits/stdc++.h>
using namespace std;

// Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

int dfs(int ROW, int COL, int curRow, int curCol, vector<vector<int>>& matrix, vector<vector<int>>& dp, int prevVal) {
    if(curRow < 0 or curCol < 0 or curRow == ROW or curCol == COL or matrix[curRow][curCol] <= prevVal) 
        return 0;

    if(dp[curRow][curCol] != -1) return dp[curRow][curCol];

    int res = 1;
    res = max(res, 1 + dfs(ROW, COL, curRow + 1, curCol, matrix, dp, matrix[curRow][curCol]));
    res = max(res, 1 + dfs(ROW, COL, curRow - 1, curCol, matrix, dp, matrix[curRow][curCol]));
    res = max(res, 1 + dfs(ROW, COL, curRow, curCol + 1, matrix, dp, matrix[curRow][curCol]));
    res = max(res, 1 + dfs(ROW, COL, curRow, curCol - 1, matrix, dp, matrix[curRow][curCol]));

    dp[curRow][curCol] = res;
    return res;
}


int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ROW = matrix.size(), COL = matrix[0].size();
    vector<vector<int>> dp(ROW, vector<int>(COL,-1));
    
    int ans = 0;
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(dp[i][j] == -1) {
                dfs(ROW,COL,i,j, matrix, dp, -1);
            }
        }
    } 
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
int main() {
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(matrix)<<endl;
}


