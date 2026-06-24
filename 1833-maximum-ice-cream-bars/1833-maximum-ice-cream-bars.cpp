class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0,i=0;
        sort(costs.begin(), costs.end());
        while(i<costs.size()){
            if(coins >= costs[i]){
                ans++;
                coins-=costs[i];
                i++;
            }
            else break;
        }
        return ans;
    }
};