class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> q = new LinkedList<>();
        for (int s : students) q.offer(s);
        int i = 0;
        int cnt = 0;

        while (!q.isEmpty() && cnt < q.size()) {
            if (q.peek() == sandwiches[i]) {
                q.poll();
                i++;
                cnt = 0;
            } else {
                q.offer(q.poll());
                cnt++;
            }
        }

        return q.size();
    }
}