/**
 * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    const cnt = {};
    for(const item of text) {
        cnt[item] = (cnt[item] || 0) + 1;
    }
    return Math.min(cnt['b'] || 0, cnt['a'] || 0, Math.floor((cnt['l']||0)/2), Math.floor((cnt['o'] || 0) / 2), cnt['n'] || 0);
};