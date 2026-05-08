class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(), ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(j-1 >= 0 and grid[i][j-1] == 1) ans-=2;
                    if(i-1>= 0 and grid[i-1][j] == 1) ans-=2;
                }
            }
        }   
        return ans;
    }
};