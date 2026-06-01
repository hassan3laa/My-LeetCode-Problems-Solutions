class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.rbegin(), a.rend());
        int ans=0, n=a.size();
        for(int i=0; i<n; i++) {
            if((i+1) % 3 != 0) {
                ans+=a[i];
            }
        }
        return ans;
    }
};