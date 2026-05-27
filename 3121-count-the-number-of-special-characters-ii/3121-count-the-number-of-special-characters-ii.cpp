class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int>lower(26,-1), upper(26,1e9);
        for(int i=0;i<s.size();i++) {
            char c=s[i];
            if(islower(c)){
                lower[c-'a']=i;
            } else {
                upper[c-'A']=min(upper[c-'A'],i);
            }
        }
        int ans=0;
        for(int i=0;i<26;i++) {
            if(lower[i]!=-1 and upper[i]!=1e9 and lower[i]<upper[i]) ans++;
        }
        return ans;
    }
};