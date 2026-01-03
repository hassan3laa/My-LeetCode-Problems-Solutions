class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t = 0;
        int ans = tickets[k];
        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k) {
                t += min(tickets[i], ans);
            } else {
                t += min(tickets[i], ans - 1);
            }
        }
        return t;
    }
};