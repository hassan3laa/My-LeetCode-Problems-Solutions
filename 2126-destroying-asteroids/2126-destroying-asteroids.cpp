class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(), a.end());
        long long m1=mass;
        for(int x:a) {
            if(m1<x) {
                return false;
            }
            m1+=x;
        }
        return true;
    }
};