/**
 * @param {number[]} nums
 * @return {number}
 */
var findGCD = function(nums) {
    var gcd=(a,b)=>{
        while(b!==0) {
            [a,b]=[b,a%b];
        }
        return a;
    }
    let mn=nums[0], mx=nums[0];
    for(let i=1;i<nums.length;i++) {
        if(mn>nums[i]) mn=nums[i];
        if(mx<nums[i]) mx=nums[i];
    }
    return gcd(mn,mx);
};