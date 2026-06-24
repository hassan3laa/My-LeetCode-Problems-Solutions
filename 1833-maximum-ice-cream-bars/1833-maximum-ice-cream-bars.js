/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    const freq = new Array(100001).fill(0);
    for(const item of costs){
        freq[item]++;
    }
    let ans=0;
    for(let cost=1;cost<=100000;cost++) {
        if(freq[cost]==0) {
            continue;
        }
        const canBuy = Math.min(freq[cost], Math.floor(coins / cost));
        ans += canBuy;
        coins -= canBuy * cost;
        if (coins < cost) break;
    }
    return ans;
};