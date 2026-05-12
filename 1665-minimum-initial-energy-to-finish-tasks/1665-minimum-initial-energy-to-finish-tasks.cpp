class Solution {
public:
    static bool srt(vector<int>& a, vector<int>& b) {
        return (a[1]-a[0]) > (b[1]-b[0]);
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), srt);
        int ans=0, curr=0;
        for(auto& task: tasks) {
            int actual= task[0], mn= task[1];
            if(curr< mn){
                ans+=(mn- curr);
                curr=mn;
            }
            curr-=actual;
        }
        return ans;
    }
};