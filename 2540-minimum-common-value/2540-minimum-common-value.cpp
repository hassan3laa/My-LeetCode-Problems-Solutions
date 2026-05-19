class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        long long ans=1e18;
        set<int>s;
        for(int i=0;i<nums1.size();i++) s.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++) {
            if(s.count(nums2[i])) {
                ans=min(ans,(long long)nums2[i]);
            }
        }
        return (ans == 1e18 ? -1 : ans);
    }
};