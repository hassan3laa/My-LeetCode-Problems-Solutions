class Solution {
public:
    const int MOD=1e9+7;
    long long pw(long long x,long long y) {
        long long ans=1;
        while(y) {
            if(y&1) ans=ans*x%MOD;
            x=x*x%MOD;
            y>>=1;
        }
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans=0;
        for(long long num:nums){
            long long w=num%10, d=num/10, div=1, tmp=d;
            while(tmp>=10){
                tmp/=10;
                div*=10;
            } 
            for(int i=1;i<w;i++){
                div/=10;
            }
            long long x=d/div, y=d%div;
            ans=(ans+pw(x,y))%MOD;
        }
        return ans;
    }
};