class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>cnt(51);
        for(int i=0;i+k<=nums.size();i++) {
            set<int>st;
            for(int j=i;j<i+k;j++){
                st.insert(nums[j]);
            }
            for(int x:st){
                cnt[x]++;
            }
        }
        for(int i=50;i>=0;i--){
            if(cnt[i]==1) return i;
        }
        return -1;
    }
};