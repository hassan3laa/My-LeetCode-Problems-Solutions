class Solution {
public:
    int digit(int x) {
        int ans=0;
        while(x > 0) {
            ans+=(x%10);
            x/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            nums[i]=digit(nums[i]);
        }
        return *min_element(nums.begin(), nums.end());
    }
};