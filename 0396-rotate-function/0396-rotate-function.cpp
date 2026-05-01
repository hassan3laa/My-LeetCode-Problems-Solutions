class Solution {
public:
typedef long long ll;
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        ll sum=0, f0=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            f0 += 1ll * i * nums[i];
        }
        ll ans= f0;
        for(int i=1; i<n; i++){
            f0 = f0 + sum- 1ll*n*nums[n-i];
            ans = max(ans, f0);
        }
        return ans;
    }
};