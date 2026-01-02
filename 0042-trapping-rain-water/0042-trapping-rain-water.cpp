class Solution {
public:
    int trap(vector<int>& a) {
        int start = 0;
        int end = a.size() - 1;

        int startmax = a[start];
        int endmax = a[end];

        int sum = 0;

        while (start < end) {
            if (startmax < endmax) {
                start++;
                startmax = max (startmax, a[start]);
                sum += startmax - a[start];
            } else {
                end--;
                endmax = max (endmax, a[end]);
                sum += endmax - a[end];
            }
        }

        return sum;
    }
};