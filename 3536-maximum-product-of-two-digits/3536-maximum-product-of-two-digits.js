/**
 * @param {number} n
 * @return {number}
 */
var maxProduct = function(n) {
    let a=n.toString().split("").toSorted((a,b)=>b-a);
    return Number(a[0])*Number(a[1]);
};