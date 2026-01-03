class Solution {
    public int numOfWays(int n) {
        final int MOD = 1_000_000_007;
        long dpA = 6;
        long dpB = 6;
        for (int i = 2; i <= n; i++) {
            long newa = (2 * dpA + 2 * dpB) % MOD;
            long newb = (2 * dpA + 3 * dpB) % MOD;
            dpA=newa; dpB=newb;
        }
        return (int)((dpA + dpB) % MOD);
    }
}