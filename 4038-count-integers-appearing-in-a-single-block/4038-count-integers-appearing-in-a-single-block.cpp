class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        mp[nums[0]]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) mp[nums[i]]++;
        }
        int ans=0;
        for(auto p:mp) {
            if(p.second==1) ans++;
        }
        return ans;
    }
};