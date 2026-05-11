class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>tmp;
            while(nums[i]) {
                tmp.push_back(nums[i]%10);
                nums[i]/=10;
            }
            for(int j=tmp.size()-1;j>=0;j--) {
                ans.push_back(tmp[j]);
            }
        }
        return ans;
    }
};