/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {
    let sorted = [...arr].sort((a,b) => a-b);
    let mp=new Map();
    let rank=1;
    for(const x of sorted) {
        if(!mp.has(x)) {
            mp.set(x,rank);
            rank++;
        }
    }
    return arr.map(x=> mp.get(x));
};