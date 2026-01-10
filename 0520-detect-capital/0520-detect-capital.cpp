class Solution {
public:
    bool detectCapitalUse(string word) {
        if (capital(word) || small(word) || f_cap (word)) return true;
        else return false;
    }
    bool capital (string s) {
        int ans = 0;
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') ans++;
        }
        return ans == s.size();
    }
    bool small(string s) {
        int ans = 0;
        for(char c : s) {
            if (c >= 'a' && c <= 'z') ans++;
        }
        return ans == s.size();
    }
    bool f_cap (string s) {
        if (!(s[0] >= 'A' && s[0] <= 'Z'))
            return false;

        for (int i = 1; i < s.size(); i++) {
            if (!(s[i] >= 'a' && s[i] <= 'z'))
                return false;
        }

        return true;
    }
};