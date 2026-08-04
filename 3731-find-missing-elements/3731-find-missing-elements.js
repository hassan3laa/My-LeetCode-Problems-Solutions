/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    const binarySearch = (nums,target) => {
        let start=0,end=nums.length-1;
        while(start<=end){
            const mid=Math.floor((start+end)/2);
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
    nums.sort((a,b)=>a-b);
    let ans=[];
    for(let x=nums[0];x<=nums[nums.length-1];x++){
        if(!binarySearch(nums,x)) ans.push(x);
    }
    return ans;
};