class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string tmp = "";
        for (char c : s) {
            if (c != ' ') tmp += c;
            else {
                reverse(tmp.begin(), tmp.end());
                ans += tmp + ' ';
                tmp = "";
            }
        }
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
        return ans;
    }
};