class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto &e: edges) {
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        queue<int>q;
        vis[source]=1;
        q.push(source);
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            if(u==destination) return true;
            for(auto v: adj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        return false;
    }
};