class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // bulding a next greater for nums 2 and assign -1 for values that's dosen't have a greater value
        map<int,int> mp;
        stack<int> st;
        for (int x : nums2)
        {
            while(!st.empty() and x>st.top()) 
            {
                mp[st.top()] = x;
                st.pop();
            }   
            st.push(x);
        }
        while(!st.empty()){
            mp[st.top()]=-1;
            st.pop();
        }
        vector<int>ans;
        for(int i : nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};