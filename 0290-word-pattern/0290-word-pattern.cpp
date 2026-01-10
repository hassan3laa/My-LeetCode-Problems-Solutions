class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string tmp = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(tmp);
                tmp="";
            } else {
                tmp += c;
            }
        }
        words.push_back(tmp);
        if (pattern.size() != words.size()) return false;
        map<char, string> mp1;
        map<string, char> mp2;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (mp1.count(c)) {
                if (mp1[c] != w) {
                    return false;
                } 
            }
            else{
                mp1[c] = w;
            }
            if (mp2.count(w)) {
                if (mp2[w] != c) {
                    return false;
                }
            } else {
                mp2[w]=c;
            }
        }
        return true;
    }
};