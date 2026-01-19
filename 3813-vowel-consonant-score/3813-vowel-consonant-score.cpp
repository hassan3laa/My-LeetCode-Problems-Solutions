class Solution {
public:
    int vowelConsonantScore(string s) {
        int v=0,a=0;
        for(char c:s){
            if(c>='a'&&c<='z'){
                if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')v++;
                else a++;
            }
        }
        return a==0?0:v/a;
    }
};