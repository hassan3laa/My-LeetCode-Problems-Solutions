class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string &word){
        if (idx==word.size()) return true;
        if(i<0 or j<0 or i>=n or j>=m) {
            return false;
        }
        if(vis[i][j]){
            return false;
        }
        if(board[i][j] != word[idx]) {
            return false;
        }
        vis[i][j]= true;
        for(int d=0;d<4;d++){
            int nx=i+dx[d];
            int ny=j+dy[d];
            if(dfs(nx,ny,idx+1,board,word)) {
                return true;
            }
        }
        vis[i][j]= false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        vis.assign(n, vector<bool> (m));
        vector<pair<int,int>> starts;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]){
                    starts.push_back({i,j});
                }
            }
        }
        for(auto [i,j]: starts) {
            if(dfs(i, j, 0, board, word)){
                return true;
            }
        }
        return false;
    }
};