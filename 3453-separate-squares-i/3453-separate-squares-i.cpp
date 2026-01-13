class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = 0;
        for (auto &s : squares) {
            double y = s[1], l = s[2];
            total += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }
        double target = total / 2.0;
        for (int it = 0; it < 100; it++) {
            double mid = (low + high) / 2.0;
            double area = 0;
            for (auto &s : squares) {
                double y = s[1], l = s[2];

                if (mid <= y) {
                } else if (mid >= y + l) {
                    area += l * l;
                } else {
                    area += l * (mid - y);
                }
            }
            if (area < target)low = mid;
            else high = mid;
        }
        return low;
    }
};