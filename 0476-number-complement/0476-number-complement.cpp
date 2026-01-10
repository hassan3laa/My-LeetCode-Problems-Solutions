class Solution {
public:
    int findComplement(int num) {
        string bin = "";
        while (num > 0) {
            bin += (num % 2 == 0 ? '0' : '1');
            num /= 2;
        }

        reverse(bin.begin(), bin.end());
        for (char &c : bin) {
            if (c == '0') c = '1';
            else c = '0';
        }

        int res = 0;
        for (char c : bin) {
            res = res * 2 + (c - '0');
        }

        return res;
    }
};