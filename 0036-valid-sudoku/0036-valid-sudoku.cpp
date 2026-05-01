class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            bool row[9] = {};
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(row[num]) return false;
                row[num] = true;
            }
        }

        for(int j=0; j<9; j++) {
            bool col[9] = {};
            for(int i=0; i<9; i++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if(col[num]) return false;
                col[num] = true;
            }
        }
        for(int rr = 0; rr < 3; rr++) {
            for(int cc = 0; cc < 3; cc++) {
                bool seen[9] = {};
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        int r = rr * 3 + i;
                        int c = cc * 3 + j;
                        if(board[r][c] == '.') continue;
                        int num = board[r][c] - '1';
                        if(seen[num]) return false;
                        seen[num] = true;
                    }
                }
            }
        }
        return true;
    }
};