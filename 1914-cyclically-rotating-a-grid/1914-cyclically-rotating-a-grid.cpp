class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        int layers= min(n,m)/2;
        for(int layer=0; layer< layers; layer++) {
            int top= layer, left= layer;
            int bottom= n-layer-1, right= m-layer-1;
            int len= 2*(right-left + bottom-top);
            int rot= k%len;
            while(rot--){
                int tmp=grid[top][left];
                for(int i=left; i<right; i++) {
                    grid[top][i]= grid[top][i+1];
                }
                for(int i=top; i<bottom; i++) {
                    grid[i][right]= grid[i+1][right];
                }
                for(int i=right; i>left; i--) {
                    grid[bottom][i]= grid[bottom][i-1];
                }
                for (int i=bottom; i>top+1; i--) {
                    grid[i][left] = grid[i-1][left];
                }
                grid[top+1][left]= tmp;
            }
        }
        return grid;
    }
};