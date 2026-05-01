class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool valid (vector<vector<char>>&a, int r, int c, char ch){
        for(int i=0; i<9; i++) {
            if(a[r][i] == ch) return false;
            if(a[i][c] == ch) return false;
            int row = 3* (r/3) + i/3;
            int col = 3* (c/3) + i%3;
            if(a[row][col] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(valid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};