class Solution {
public:
    int arrangeCoins(int x) {
        int ans = 0;
        for (int i = 1; i <= x; i++) {
            if (x >= i) {
                ans++;
                x-=i;
            }
        }
        return ans;
    }
};