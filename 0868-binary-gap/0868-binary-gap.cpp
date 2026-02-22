class Solution {
public:
    string bit(int n){
        string s="";
        while(n>0){
            if(n%2==0){
                s+='0';
            } else if(n%2==1){
                s+='1';
            }
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int binaryGap(int n) {
        int ans=0,last=-1;
        string s=bit(n);
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(last!=-1){
                    ans=max(ans,i-last);
                }
                last=i;
            }
        }        
        return ans;
    }
};