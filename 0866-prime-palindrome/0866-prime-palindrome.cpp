class Solution {
public:

    bool isprime(int x) {
        if(x <= 1) return false;
        for(int i=2; i*i<=x; i++) {if(x%i == 0) return false;}
        return true;
    }

    int primePalindrome(int x) {
        if(x <= 11) {
            vector<int> ans= {2,3,5,7,11};
            for(int s : ans) {
                if (s>= x) return s;
            }
        }
        for(int i=1; i< 100000; i++) {
            string s= to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            string pal = s+ rev.substr(1);
            int num = stoi(pal);
            if(num >= x and isprime(num)) return num;
        }
        return -1;
        
    }
};