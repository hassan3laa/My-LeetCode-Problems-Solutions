class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans=0;
        int x=p[0][0], y=p[0][1];
        for (int i=1;i<p.size();i++){
            int xi = p[i][0], yi = p[i][1];
            while(x != xi || y != yi){
                if(x < xi) x++;
                else if(x > xi) x--;
                if(y < yi) y++;
                else if(y > yi) y--;
                ans++;
            }
        }
        return ans;
    }
};