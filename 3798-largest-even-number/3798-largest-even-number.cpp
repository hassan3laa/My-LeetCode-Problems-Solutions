class Solution {
public:
    string largestEven(string s) {
        int two=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='2') two=i;
        }    
        if(two==-1)return "";
        return s.substr(0,two+1);
    }
};