class Solution {
public:
    int numberOfSpecialChars(string s) {
        map<char,int>mp;
        int ans=0, n=s.size();
        for(int i=0;i<n;i++) {
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++) {
            if(s[i] >= 'a' and s[i] <= 'z' and mp[s[i]]>0) {
                if(mp[s[i]] >= 1 and mp[toupper(s[i])] >= 1) {
                    ans++;
                    mp[s[i]]=0;
                }
            }
        }
        return ans;
    }
};