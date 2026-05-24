class Solution {
public:
    vector<int>dp;
    int n,d;
    int dfs(int i, vector<int>&a) {
        if(dp[i] != -1) {
            return dp[i];
        }
        int ans=1;
        for(int j=i+1; j<=min(n-1, i+d); j++) { // to right
            if(a[j] >= a[i]) break;
            ans=max(ans,1+dfs(j,a));
        }
        for (int j=i-1; j>= max(0, i-d); j--) { // to left
            if(a[j] >= a[i]) break;
            ans=max(ans,1+dfs(j,a));
        }
        return dp[i]=ans;
    }
    
    int maxJumps(vector<int>& arr, int D) {
        n=arr.size(), d=D;
        dp.assign(n,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,arr));
        }
        return ans;
    }
};