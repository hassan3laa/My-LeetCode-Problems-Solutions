class Solution {
public:
    int maxArea(vector<int>& a) {
        int left = 0, right = a.size()-1;
        int ans=0;
        while(left<right){
            int area = min(a[left],a[right]) * (right-left);
            ans = max(ans,area);
            if (a[left] < a[right]) left++;
            else right--;
        }
        return ans;
    }
};