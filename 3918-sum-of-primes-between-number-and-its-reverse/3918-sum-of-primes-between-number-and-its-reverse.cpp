class Solution {
public:
    int rev(int x) {
        int r = 0;
        while(x> 0) {
            r = r * 10 + (x%10);
            x/=10;
        }
        return r;
    }


    vector<bool> sieve(int x) {
        vector<bool> primes(x+1,true);
        primes[0] = primes[1] = false;
        for(int i=2; i*i<=x; i++) {
            if(primes[i]) {
                for(int j=i*i; j<=x; j+=i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }



    int sumOfPrimesInRange(int n) {
        int r = rev(n);
        int L = min(n,r);
        int R = max(n,r);
        vector<bool> prime = sieve(1000);

        vector<int>pref(1001, 0);
        for(int i=1;i<=1000; i++) {
            pref[i] = pref[i-1];
            if(prime[i]) pref[i] += i;
        }
        if(L == 0) return pref[R];
        return pref[R] - pref[L-1];
    }
};