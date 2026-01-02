class Solution {
    public List<String> buildArray(int[] a, int n) {
        List<String> ans=new ArrayList<>();
        int idx=0; // for target list
        for (int i=1;i<=n;i++){
            if (idx==a.length) break;
            if(i == a[idx]) {
                ans.add("Push");
                idx++;
            } else{
                ans.add("Push");
                ans.add("Pop");
            }
        }
        return ans;
    }
}