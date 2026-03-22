class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0; i < 4; i++) {
            if(same(mat,target)) return true;
            rotate(mat);
        }
        return false;
    }

    bool same(vector<vector<int>>& a, vector<vector<int>>& b) {
        return a == b;
    }
    void rotate (vector<vector<int>>& mat){
        int n = mat.size();
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse each row
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};