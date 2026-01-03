class Solution {
    public int[] finalPrices(int[] a) {
        int x = a.length;
        int[]ans = Arrays.copyOf(a,x);
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < x; i++) {
            while (!st.isEmpty() && a[i] <= a[st.peek()]){
                int idx = st.pop();
                ans[idx] -= a[i];
            }
            st.push(i);
        }
        return ans;
    }
}