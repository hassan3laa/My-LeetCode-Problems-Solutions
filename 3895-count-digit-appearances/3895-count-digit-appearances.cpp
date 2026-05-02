class Solution {
public:

    int appearance (int x, int s){
        int ans=0;
        while(x>0) {
            int d = x%10;
            ans += (d == s);
            x/=10;
        }
        return ans;
    }

    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans += appearance(nums[i], digit);
        }
        return ans;
    }
};