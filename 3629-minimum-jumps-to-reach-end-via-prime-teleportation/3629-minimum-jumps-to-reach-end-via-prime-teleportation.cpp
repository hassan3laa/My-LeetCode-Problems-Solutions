class Solution {
public:

    vector<int>spf;
    void sieve(int x) {
        spf.assign(x+1,0);
        for(int i=0;i<=x;i++) spf[i]=i;
        for(int i=2;i*i<=x;i++){
            if(spf[i]==i){
                for(int j=i*i; j<=x; j+=i) {
                    if(spf[j] == j)
                        spf[j]=i;
                }
            }
        }
    }
    bool isprime(int x) {
        return x > 1 and spf[x]==x;
    }
    vector<int> fac(int x){
        vector<int> ans;
        while(x>1){
            int p=spf[x];
            ans.push_back(p);
            while(x%p==0) x/=p;
        }
        return ans;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        sieve(mx);
        map<int, vector<int>> mp;
        for(int i=0;i<n;i++){
            vector<int>factors=fac(nums[i]);
            for(int s:factors){
                mp[s].push_back(i);
            }
        }
        vector<int>dis(n,-1);
        queue<int>q;
        dis[0]=0;
        q.push(0);
        set<int>primes;
        while(!q.empty()) {
            int i=q.front();
            q.pop();
            if(i==n-1) {
                return dis[i];
            }
            if(i-1 >= 0 and dis[i-1]==-1) {
                dis[i-1]= dis[i]+1;
                q.push(i-1);
            }
            if(i+1 < n and dis[i+1]==-1){
                dis[i+1]=dis[i]+1;
                q.push(i+1);
            }
            int val=nums[i];
            if(isprime(val) and !primes.count(val)){
                for(int s:mp[val]){
                    if(dis[s]==-1){
                        dis[s]=dis[i]+1;
                        q.push(s);
                    }
                }
                primes.insert(val);
            }
        }
        return -1;
    }
};