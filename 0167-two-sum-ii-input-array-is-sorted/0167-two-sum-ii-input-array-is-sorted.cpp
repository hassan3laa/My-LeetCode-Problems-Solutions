class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int n = a.size();

        int start = 0 , end = a.size() - 1 ;

        while(start <= end) {
            int sum = a[start] + a[end] ; 

            if (sum == x) {
                return {start + 1 , end + 1};
            }
            else if (sum < x) {
                start ++ ;
            } else {
                end --;
            }
        }

        return {};
    }
};