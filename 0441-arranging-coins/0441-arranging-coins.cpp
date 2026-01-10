class Solution {
public:
    int arrangeCoins(int x) {
        long long start = 1, end = x, ans=0;
        while (start <= end) {
            long long mid=(start+end) /2;
            long long val = mid * (mid+1);
            val /=2;
            if (val == x){
                ans=mid;
                break;
            } else if (val < x) {
                ans = mid;
                start = mid + 1;
            } else end = mid - 1;
        }
        return ans;
    }
};