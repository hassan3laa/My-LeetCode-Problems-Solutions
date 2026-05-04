class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int x=a.size();
        for(int i=0;i<x;i++){
            for(int j=i; j<x; j++) {
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i=0;i<x;i++){
            reverse(a[i].begin(), a[i].end());
        }
    }
};