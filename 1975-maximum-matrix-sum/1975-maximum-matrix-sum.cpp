class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& a) {
        int x=a.size();
        long long ans = 0, nega = 0, mn = LLONG_MAX;
        for (int i = 0; i < x; i++) {
            for (int ii = 0; ii < x; ii++) {
                ans += abs(a[i][ii]);
                if (a[i][ii] < 0) nega++;
                mn = min(mn, abs((long long)a[i][ii]));
            }
        }

        if (nega % 2 == 1) {
            ans -= 2LL*mn;
        }
        return ans;
    }
};