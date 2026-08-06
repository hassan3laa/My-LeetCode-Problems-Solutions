/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    let num=n;
    let ans=1;
    while(num){
        ans*=num%10;
        num=Math.floor(num/10);
    }
    if(ans%t==0) {
        return n;
    }
    return smallestNumber(n+1,t);
};