/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    let nums = [];
    while(n) {
        nums.push(n%10);
        n=Math.floor(n/10);
    }
    const x=nums.length;
    nums.sort((a,b)=>a-b);
    return nums[x-1]*nums[x-2];
};