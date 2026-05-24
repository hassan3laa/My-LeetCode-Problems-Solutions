/**
 * @param {number[]} arr
 * @param {number} d
 * @return {number}
 */
var maxJumps = function(arr, d) {
    const n=arr.length;
    const dp=new Array(n).fill(-1);
    const dfs=(i)=> {
        if(dp[i] !== -1) {
            return dp[i];
        } 
        dp[i]=1;
        for(let j=i-1; j>=0 && i-j <= d && arr[i] > arr[j]; j--) {
            dfs(j);
            dp[i] = Math.max(dp[i], dp[j]+1);
        }
        for(let j=i+1; j<n && j-i <= d && arr[i] > arr[j]; j++) {
            dfs(j);
            dp[i] = Math.max(dp[i], dp[j]+1);
        }
    };
    for(let i=0;i<n;i++){
        dfs(i);
    }
    return Math.max(...dp);
};