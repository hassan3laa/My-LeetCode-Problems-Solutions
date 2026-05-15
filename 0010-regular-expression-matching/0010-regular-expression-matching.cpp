class Solution {
public:
    int dp [25][25];
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,s,p);
    }

    bool solve(int i, int j, string& s, string& p) {
        if(j == p.size()) {
            return i == s.size();
        }      
        int &ans= dp[i][j];
        if(ans != -1) return ans;
        bool match= (i < s.size() and (s[i] == p[j] or p[j] == '.'));
        if(j+1<p.size() and p[j+1] == '*') {
            return ans = (solve(i,j+2,s,p) or (match and solve(i+1,j,s,p)));
        }
        return ans = (match and solve(i+1,j+1,s,p));
    }
};