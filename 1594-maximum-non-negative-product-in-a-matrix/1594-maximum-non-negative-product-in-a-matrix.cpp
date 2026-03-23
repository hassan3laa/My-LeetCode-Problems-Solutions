class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;
    int m, n;
    vector<vector<int>> grid;
    pair<ll,ll> memo[16][16];
    bool vis[16][16];
    pair<ll,ll> dfs(int i, int j) {

        if (i == m-1 && j == n-1)
            return {grid[i][j], grid[i][j]};

        if (vis[i][j]) return memo[i][j];
        vis[i][j] = true;
        ll mx = -INF;
        ll mn = INF;
        if (i + 1 < m) {
            auto [a,b] = dfs(i+1, j);
            mx = max(mx, max(a*grid[i][j], b*grid[i][j]));
            mn = min(mn, min(a*grid[i][j], b*grid[i][j]));
        }
        if (j + 1 < n) {
            auto [a,b] = dfs(i, j+1);
            mx = max(mx, max(a*grid[i][j], b*grid[i][j]));
            mn = min(mn, min(a*grid[i][j], b*grid[i][j]));
        }
        return memo[i][j] = {mx, mn};
    }
    int maxProductPath(vector<vector<int>>& g) {
        grid = g;
        m = g.size();
        n = g[0].size();
        auto [mx, mn] = dfs(0,0);
        if (mx < 0) return -1;
        return mx % (long long)(1e9+7);
    }
};