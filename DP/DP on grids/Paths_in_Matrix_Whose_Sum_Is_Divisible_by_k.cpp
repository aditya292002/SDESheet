class Solution {
public:


int mod = 1e9 + 7;

int numberOfPathsUtil(vector<vector<int>>& grid, int k, int i, int j, int sum, vector<vector<vector<int>>> &dp) {
    if(i == grid.size() - 1 and j == grid[0].size() - 1) { 
        sum += grid[i][j];
        if(sum % k == 0) return 1;
        return 0;
    }

    if(dp[i][j][sum%k] != -1) return dp[i][j][sum%k];  // Sum % k works
            /*
                say upto grid[x][y] sum of path is Sum
                and sum % k = a
                i.e. a is extra 

                i.e. if earlier with extra we were able to find a path whose total sum was
                        a multiple of k 
                    
            */

    long long down = 0, right = 0;
    if(i + 1 < grid.size()) {
        down = (numberOfPathsUtil(grid, k, i + 1, j, sum + grid[i][j], dp)) % mod;
    }
    if(j + 1 < grid[0].size()) {
        right = (numberOfPathsUtil(grid, k, i, j + 1, sum + grid[i][j], dp)) % mod;
    }

    long long ans = (down + right) % mod;
    return dp[i][j][sum%k] = ans;
    // return down + right;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int n = grid.size(); int m = grid[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1,  vector<int>(k + 1, -1)));
    return numberOfPathsUtil(grid, k, 0, 0, 0, dp);
}
};