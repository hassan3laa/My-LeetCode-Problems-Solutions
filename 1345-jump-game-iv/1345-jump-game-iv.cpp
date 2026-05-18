class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        map<int,vector<int>>mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>vis (n,false);
        q.push(0);
        vis[0]=true;
        int ans=0;
        while(!q.empty()) {
            int sz=q.size();
            while(sz--){
                int cur=q.front();
                q.pop();
                if(cur==n-1) {
                    return ans;
                }
                vector<int>nxt;
                for(int idx:mp[nums[cur]]) {
                    nxt.push_back(idx);
                }
                if(cur+1<n) nxt.push_back(cur+1);
                if(cur-1>=0) nxt.push_back(cur-1);
                for(int v:nxt) {
                    if(!vis[v]) {
                        q.push(v);
                        vis[v]=true;
                    }
                }
                mp[nums[cur]].clear();
            }
            ans++;
        }
        return -1;
    }
};