class Solution {
public:
    int search(vector<int>& a, int n) {
        int start = 0, end = a.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (a[mid] == n) {
                return mid;
            } else if (a[mid] >= a[start]) {
                if (a[start] <= n && n <= a[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (a[mid] <= n && n <= a[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;      
    }
};