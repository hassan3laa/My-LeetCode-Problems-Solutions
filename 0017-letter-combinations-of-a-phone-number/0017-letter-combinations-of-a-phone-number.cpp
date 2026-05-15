class Solution {
public:
    vector<string>ans;
    vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) {
            return {};
        }
        solve(0,"",digits);
        return ans;
    }
    void solve(int idx, string curr, string &s) {
        if(idx== s.size()) {
            ans.push_back(curr);
            return;
        }
        string ss = mp[s[idx]-'0'];
        for(char c : ss) {
            solve(idx+1, curr+c, s);
        }
    }
};