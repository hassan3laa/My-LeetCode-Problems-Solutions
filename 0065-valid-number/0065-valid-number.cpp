class Solution {
public:
    bool isNumber(string s) {
        bool isd = false, num = false, ise=false;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))num=true;
            else if (s[i] =='+' or s[i] == '-') {
                if (i > 0 and (s[i-1] != 'e' && s[i-1] != 'E')) return false;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (ise or !num) return false;
                ise = true, num=false;
            }
            else if (s[i] == '.') {
                if (isd or ise) return false;
                isd = true;
            } else return false;
        }
        return num;
    }
};