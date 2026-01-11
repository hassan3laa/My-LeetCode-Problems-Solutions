class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return (is1(nums) || is2(nums));
    }
    bool is1 (vector<int>&a) {
        bool ok = true;
        for (int i=1;i<a.size();i++) {
            if (a[i] < a[i-1]){
                ok = false;
                break;
            }
        }
        return ok;
    }
    bool is2 (vector<int>&a) {
        bool ok = true;
        for (int i=1;i<a.size();i++) {
            if (a[i] > a[i-1]){
                ok = false;
                break;
            }
        }
        return ok;
    }
};