/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    nums.sort((a,b)=>a-b);
    let ans=[];
    for(let i=1;i<nums.length;i++){
        for(let x=nums[i-1]+1;x<nums[i];x++){
            ans.push(x);
        }
    }
    return ans;
};