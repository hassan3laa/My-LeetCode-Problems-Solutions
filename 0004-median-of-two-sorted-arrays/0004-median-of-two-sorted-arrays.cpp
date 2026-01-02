class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> a;

        for (auto num : nums1) {
            a.push_back(num);
        }

        for (auto num : nums2) {
            a.push_back(num);
        }

        sort (a.begin() , a.end());

        int n = a.size();

        return n % 2 ? a[n / 2] : (a[n / 2 - 1] + a[n / 2]) / 2.0;
    }
};