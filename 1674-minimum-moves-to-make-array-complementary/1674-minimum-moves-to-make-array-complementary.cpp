class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        map<int,int>freq;
        vector<int>mn, mx;
        mn.reserve(n/2), mx.reserve(n/2);
        for(int i=0; i<n/2; i++) {
            int a=min(nums[i], nums[n-i-1]), b=max(nums[i],nums[n-i-1]);
            freq[a+b]++;
            mn.push_back(a);
            mx.push_back(b);
        }
        sort(mn.begin(), mn.end());
        sort(mx.begin(), mx.end());
        int ans=n;
        for(int i=2; i<=2*limit; i++) {
            int added_left= n/2- (lower_bound(mn.begin(), mn.end(), i)- mn.begin());
            int added_right=lower_bound(mx.begin(), mx.end(), i-limit)- mx.begin();
            int cur= n/2+added_left+added_right-freq[i];
            ans=min(ans,cur);
        }
        return ans;
    }
};