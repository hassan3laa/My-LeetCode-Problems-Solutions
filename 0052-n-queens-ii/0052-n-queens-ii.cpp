class Solution {
public:
    vector<vector<string>>ans;
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0, board, n);
        return ans.size();
    }
    void solve(int row, vector<string>& board, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++) {
            if(safe(row,col,board,n)) {
                board[row][col]='Q';
                solve(row+1,board,n);
                board[row][col]='.';
            }
        }
    }
    bool safe(int row, int col, vector<string>& board, int n) {
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q')
                return false;
        }   
        for(int i=row-1, j=col-1; i>=0 and j>=0; i--, j--) {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row-1, j=col+1; i>=0 and j<n; i--,j++) {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};