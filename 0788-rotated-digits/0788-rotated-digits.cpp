class Solution {
public:

    bool good(int x) {
        bool ok = false;
        while(x > 0) {
            int d=x%10;
            if(d == 3 or d==4 or d==7) return false;
            if(d==2 or d==6 or d==5 or d==9) ok =true;
            x/=10;
        }
        return ok;
    }

    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1; i<=n; i++) {
            if(good(i)) ans++;
        }
        return ans;
    }
};