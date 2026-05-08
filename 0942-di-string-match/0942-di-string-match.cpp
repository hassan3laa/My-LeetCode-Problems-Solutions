class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>ans(n+1);
        int mn=0, mx=n;
        for(int i=0;i<n;i++){
            if(s[i] == 'I') ans[i]=mn,mn++;
            else if(s[i]=='D') ans[i]=mx,mx--;
        }
        ans[n]=mn;
        return ans;
    }
};