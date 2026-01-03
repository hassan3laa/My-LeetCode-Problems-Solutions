class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int mx = 0;
        for (int i = 0; i <= heights.length; i++) {
            int currHeight = (i == heights.length) ? 0 : heights[i];
            while (!stack.isEmpty() && currHeight < heights[stack.peek()]) {
                int h = heights[stack.pop()];
                int right = i;
                int left = stack.isEmpty() ? 0 : stack.peek() + 1;
                int width = right - left;
                mx = Math.max(mx, h * width);
            }

            stack.push(i);
        }
        return mx;
    }
}