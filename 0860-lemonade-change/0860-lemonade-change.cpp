class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int five= 0, ten=0;
        for(int i=0;i<a.size();i++) {
            if(a[i] == 5) five++;
            else if(a[i]==10){ 
                if (five == 0) {
                    return false;
                }
                    five--;
                    ten++;
            }
            else {
                if(ten >0 and five >0) {
                    ten--, five--;
                } else if(five >=3) five-=3;
                else return false;
            }
        }
        return true;
    }
};