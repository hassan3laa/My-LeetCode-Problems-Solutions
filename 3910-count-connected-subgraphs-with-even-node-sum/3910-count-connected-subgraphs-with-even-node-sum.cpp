class Solution {
public:
    int n, ans=0;
    vector<int>nums;
    vector<vector<int>>adj;

    void dfs(int u, vector<bool>& in_set, vector<bool>& vis){
        vis[u] = true;
        for(auto v : adj[u]) {
            if(in_set[v] and !vis[v]) {
                dfs(v,in_set,vis);
            }
        }
    }

    bool isconnected(vector<bool>& in_set){
        vector<bool>vis(n,false);
        int start=-1;
        for(int i=0;i<n;i++){
            if(in_set[i]) {
                start=i;
                break;
            }
        }
        dfs(start,in_set,vis);
        for(int i=0;i<n;i++){
            if(in_set[i] and !vis[i]) {
                return false;
            }
        }
        return true;
    }

    void generate(int idx, vector<bool>& in_set) {
        if (idx == n) {
            int sum = 0;
            bool empty = true;
            for (int i = 0; i < n; i++) {
                if (in_set[i]) {
                    empty = false;
                    sum += nums[i];
                }
            }
            if (empty || sum % 2 != 0) return;
            if (isconnected(in_set))ans++;
            return;
        }
        in_set[idx] = true; // take it
        generate(idx + 1, in_set);
        in_set[idx] = false; // leave
        generate(idx + 1, in_set);
    }

    int evenSumSubgraphs(vector<int>& nums_, vector<vector<int>>& edges) {
        nums=nums_;
        n=nums.size();
        ans=0;
        adj.assign(n, {});
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>in_set(n,false);
        generate(0,in_set);
        return ans;
    }
};