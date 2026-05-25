class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<int>dp(n,0), pref(n,0);
        dp[0]=1;
        for(int i=0;i<minJump;i++) {
            pref[i]=1;
            
        }
        for(int i=minJump; i<n; i++) {
            int left= i-maxJump, right=i-minJump;
            if(s[i]=='0') {
                int sum=pref[right]- (left<=0 ? 0 : pref[left-1]);
                dp[i] = (sum!=0);
            }
            pref[i]=pref[i-1] + dp[i];
        }
        return dp[n-1];
    }
};