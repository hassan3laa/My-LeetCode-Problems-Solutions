class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++) {
            int left= i-arr[i], right= i+arr[i];
            if(left>=0){
                adj[i].push_back(left);
            }
            if(right < n) {
                adj[i].push_back(right);
            }
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            if(arr[u] == 0) {
                return true;
            }
            for(auto v:adj[u]) {
                if(!vis[v]) {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};