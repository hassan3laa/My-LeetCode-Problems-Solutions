/**
 * @param {number[]} nums
 * @return {number}
 */
var uniqueXorTriplets = function(nums) {
    const n=nums.length;
    if(n<3) {
        return n;
    }
    let bits=0,x=n;
    while(x) {
        bits++;
        x>>=1;
    }
    return 1<<bits;
};