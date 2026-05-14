class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n,0);
        for(int a: nums) {
            if (a < n-1 and freq[a] > 0) return false;
            if(a==n-1 and freq[a] > 1) return false;
            if(a >= n) return false;
            freq[a]++;
        }
        return true;
    }
};