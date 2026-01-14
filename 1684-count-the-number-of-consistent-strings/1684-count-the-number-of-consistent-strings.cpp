class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = words.size();
        bool ok[26]{};
        for (char c : allowed)ok[c-'a']=true;
        for (string s : words) 
        {
            for (char c : s) 
            {
                if (!ok[c-'a']){
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};