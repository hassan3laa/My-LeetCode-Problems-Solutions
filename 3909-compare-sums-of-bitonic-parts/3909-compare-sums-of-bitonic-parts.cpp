class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum1=0, sum2=0;
        int l=0, r=nums.size()-1;
        while(l<r) {
            int mid=(l+r)/2;
            if(nums[mid] < nums[mid+1]) l =mid+1;
            else r=mid;
        }
        for(int i=0;i<=l;i++) sum1+=nums[i];
        for(int i=l;i<nums.size();i++)sum2+=nums[i];
        if(sum1==sum2)return -1;
        else if(sum1 > sum2) return 0;
        return 1;
    }
};