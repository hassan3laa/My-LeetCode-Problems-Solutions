class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int x = score.size();
        vector<string>ans(x);
        vector<pair<int,int>> val;
        for(int i=0;i<x;i++)
        {
            val.push_back({score[i],i});
        }
        sort(val.begin(),val.end(), greater<>());
        for(int i=0;i<x;i++){
            int idx=val[i].second;
            if(i == 0) ans[idx] = "Gold Medal";
            else if (i == 1) ans[idx] = "Silver Medal";
            else if (i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i+1);
        }
        return ans;
    }
};