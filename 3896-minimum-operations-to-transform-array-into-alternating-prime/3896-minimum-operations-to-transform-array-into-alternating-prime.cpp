class Solution {
public:
    int MAXN = 200005;
    vector<bool> prime;

    void sieve() {
        prime.assign(MAXN,true);
        prime[0] = prime[1] = false;
        for(int i=2;i*i<=MAXN;i++) {
            if(prime[i]) {
                for(int j=i*i; j< MAXN; j+=i){
                    prime[j] = false;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        sieve();
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(i%2==0){
                int y=x;
                while(!prime[y]) y++;
                ans += (y-x);
            } else {
                int y=x;
                while(prime[y])y++;
                ans += (y-x);
            }
        }
        return ans;
    }
};