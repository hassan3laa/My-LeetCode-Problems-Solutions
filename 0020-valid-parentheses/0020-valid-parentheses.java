class Solution {
    public boolean isValid(String s) {
        Stack <Character> st = new Stack<> ();

        for (char c : s.toCharArray()) {
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                else if (c == '}' && st.peek() != '{') return false;
                else if (c == ']' && st.peek() != '[') return false;
                else if (c == ')' && st.peek() != '(') return false;
                st.pop();
            }
        }

        return st.empty();
    }
}