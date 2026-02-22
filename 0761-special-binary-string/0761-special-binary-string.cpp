class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>ans;
        int balance=0,start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')balance++;
            else balance--;
            if(balance==0){
                string sub=s.substr(start+1,i-start-1);
                ans.push_back("1"+makeLargestSpecial(sub)+"0");
                start=i+1;
            }
        }
        sort(ans.rbegin(),ans.rend());
        string res="";
        for(auto &p:ans)res+=p;
        return res;
    }
};