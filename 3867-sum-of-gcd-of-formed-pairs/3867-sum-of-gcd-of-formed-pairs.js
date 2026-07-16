/**
 * @param {number[]} nums
 * @return {number}
 */
var gcdSum = function(nums) {
    const gcd = (a,b) => {
        while(b!==0) {
            [a,b]=[b, a%b];
        }
        return a;
    }
    const n = nums.length;
    const mx=new Array(n);
    let prefMax=-Infinity;
    for(let i=0;i<n;i++) {
        prefMax=Math.max(prefMax,nums[i]);
        mx[i]=(prefMax);
    }
    const prefGCD=new Array(n);
    for(let i=0;i<n;i++) {
        prefGCD[i]=gcd(nums[i],mx[i]);
    }
    prefGCD.sort((a,b)=>a-b); // ascending
    let ans=0, left=0, right=n-1;
    while(left<right) {
        ans+=gcd(prefGCD[left], prefGCD[right]);
        left++, right--;
    }
    return ans;
};