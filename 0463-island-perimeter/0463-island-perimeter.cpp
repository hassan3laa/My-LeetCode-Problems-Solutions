class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    int islandPerimeter(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == 1){ // find first point to search
                    q.push({i,j});
                    vis[i][j]=1;
                    i=n;
                    break;
                }
            }
        }
        int ans=0;
        while(!q.empty()) { // bfs
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];
                if(nx<0 or ny<0 or nx>=n or ny>=m) ans++;
                else if(a[nx][ny] == 0) ans++;
                else if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};