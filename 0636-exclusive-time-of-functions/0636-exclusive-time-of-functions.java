class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int[] ans = new int[n];
        Stack<Integer> st = new Stack<>();
        int prev = 0;
        for (String log : logs) {
            String[] parts = log.split(":");
            int id = Integer.parseInt(parts[0]);
            String type = parts[1];
            int t = Integer.parseInt(parts[2]);
            if (type.equals("start")) {
                if (!st.isEmpty()) {
                    ans[st.peek()] += t - prev;
                }
                st.push(id);
                prev = t;
            } else {
                ans[st.pop()] += t - prev + 1;
                prev = t + 1;
            }
        }
        return ans;   
    }
}