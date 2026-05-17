class Solution {
public:
    vector<vector<int>>adj;
    vector<bool>vis;
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        adj.assign(n,vector<int>());
        vis.assign(n,false);
        for(int i=0;i<n;i++){
            int left = (i- arr[i]), right= (i+arr[i]);
            if(left >= 0) adj[i].push_back(left);
            if(right < n) adj[i].push_back(right);
        }
        return dfs(start,arr,adj,vis);
    }

    bool dfs(int node, vector<int>&nums, vector<vector<int>>&adj, vector<bool>&vis) {
        if(nums[node]==0) return true;
        vis[node]=true;
        for(auto v : adj[node]) {
            if(!vis[v]) {
                if(dfs(v, nums, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};