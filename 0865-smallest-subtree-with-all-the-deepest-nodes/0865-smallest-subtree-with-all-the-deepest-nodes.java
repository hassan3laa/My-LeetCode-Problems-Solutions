/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();//BFS
        q.add(root);
        parent.put(root, null);
        List<TreeNode> level = new ArrayList<>();
        while (!q.isEmpty()) {
            int size = q.size();
            level.clear();
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                level.add(cur);

                if (cur.left != null) {
                    parent.put(cur.left, cur);
                    q.add(cur.left);
                }

                if (cur.right != null) {
                    parent.put(cur.right, cur);
                    q.add(cur.right);
                }
            }
        }
        // deepest nodes
        Set<TreeNode> set = new HashSet<>(level);
        // move upward until only one node remains
        while (set.size() > 1) {
            Set<TreeNode> next = new HashSet<>();
            for (TreeNode node : set) {
                next.add(parent.get(node));
            }
            set = next;
        }

        return set.iterator().next();
    }
}