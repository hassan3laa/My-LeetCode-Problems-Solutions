class Solution {
public:
    struct item {
        int val, left, right;
    };
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<item> st;
        for(int i=0;i<n;i++){
            item cur= {nums[i], i, i};
            while(!st.empty() and st.back().val > nums[i]){
                item top= st.back();
                st.pop_back();
                cur.val= max(cur.val, top.val);
                cur.left= top.left;
            }
            st.push_back(cur);
        }
        for(int i=0;i<st.size(); i++) {
            for(int j=st[i].left; j<= st[i].right; j++)
                ans[j] = st[i].val;
        }
        return ans;
    }
};