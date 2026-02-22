class Solution {
public:
    int countBinarySubstrings(string s) {
           vector<int>gr;
           int cnt=1;
           for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])cnt++;
            else{
                gr.push_back(cnt);
                cnt=1;
            }
        }
        gr.push_back(cnt);
        int ans=0;
        for(int i=1;i<gr.size();i++){
            ans+=min(gr[i],gr[i-1]);
        }
        return ans;
    }
};