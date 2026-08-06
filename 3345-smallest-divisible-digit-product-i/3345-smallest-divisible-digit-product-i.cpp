class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int x=check(i);
            if(x%t==0) {
                return i;
            }
        }
        return 0;
    }
    int check(int x) {
        int ans=1;
        while(x){
            ans*=x%10;
            x/=10;
        }
        return ans;
    }
};