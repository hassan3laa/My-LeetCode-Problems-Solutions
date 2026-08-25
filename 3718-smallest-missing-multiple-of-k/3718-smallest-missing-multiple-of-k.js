/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    let ans=k;
    const seen=new Set(nums);
    while(seen.has(ans)) ans+=k;
    return ans;
};