class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>>mp;
        int x = nums.size();
        for(int i=0;i<x;i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &it: mp){
            auto idx= it.second;
            if(idx.size() < 3) continue;
            for(int i=0; i+2<idx.size(); i++){
                int dis= abs(idx[i] - idx[i+1]) + abs(idx[i+1] - idx[i+2]) + abs(idx[i] - idx[i+2]);
                ans = min(ans,dis);
            }
        }
        return ans==INT_MAX? -1 : ans;
    }
};