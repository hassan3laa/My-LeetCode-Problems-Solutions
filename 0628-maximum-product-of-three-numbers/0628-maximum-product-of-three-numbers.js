/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumProduct = function(nums) {
    const n=nums.length;
    nums.sort((a,b)=>a-b);
    const ch1 = nums[n-1]*nums[n-2]*nums[n-3];
    const ch2 = nums[0]*nums[1]*nums[n-1];
    return Math.max(ch1,ch2);
};