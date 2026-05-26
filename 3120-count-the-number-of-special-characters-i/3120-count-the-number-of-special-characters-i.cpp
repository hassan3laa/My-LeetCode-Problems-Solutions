class Solution {
public:
    int numberOfSpecialChars(string s) {
        unordered_set<char> st(s.begin(), s.end());
        int ans=0;
        for(char c='a'; c<='z'; c++){
            if(st.count(c) and st.count(c-'a'+'A')){
                ans++;
            }
        }
        return ans;
    }
};