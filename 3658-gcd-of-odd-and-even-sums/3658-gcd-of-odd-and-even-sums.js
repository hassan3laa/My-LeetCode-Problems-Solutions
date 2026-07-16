/**
 * @param {number} n
 * @return {number}
 */
var gcdOfOddEvenSums = function(n) {
    var gcd=(a,b)=>{
        while(b!==0) {
            [a,b]=[b,a%b];
        }
        return Math.abs(a);
    }
    const sumEven=n*(n+1), sumOdd=n*n;
    return gcd(sumEven,sumOdd);
};