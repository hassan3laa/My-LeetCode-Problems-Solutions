class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i >= n or j >= m) return 1e9;
        if(i == n-1 and j == m-1) {
            return grid[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int right= dfs(i, j+1, grid);
        int down= dfs(i+1, j, grid);
        return dp[i][j]= grid[i][j]+ min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return dfs(0,0,grid);
    }
};