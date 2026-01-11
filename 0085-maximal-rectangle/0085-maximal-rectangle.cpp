class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        if (a.empty()) return 0;
        int x = a.size();
        int m = a[0].size();
        int ans = 0;
        vector<int> h(m,0);
        for (int i = 0; i < x; i++) {
            for (int j=0;j<m;j++) {
                if (a[i][j] == '1') h[j]++;
                else h[j]=0;
            }

            for (int j=0;j<m;j++){
                if (h[j]==0) continue;
                int height = h[j], left=j,right=j;
                while (left-1>=0 && h[left-1] >= height) left--;
                while (right+1 < m && h[right+1] >= height) right++;

                ans = max (ans, height*(right-left+1));
            }
        }
        return ans;
    }
};