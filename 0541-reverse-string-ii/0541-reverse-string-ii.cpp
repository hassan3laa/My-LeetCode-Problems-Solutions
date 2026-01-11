class Solution {
public:
    string reverseStr(string s, int k) {
        int x=s.size();
        for (int i=0;i<x;i += 2*k){
            int l=i,r=min(i+k-1,x-1);
            while(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};