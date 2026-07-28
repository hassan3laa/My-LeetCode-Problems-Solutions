/**
 * @param {string} s
 * @return {string}
 */
var smallestPalindrome = function(s) {
    const p = Math.floor(s.length/2);
    const freq=new Int32Array(26);
    for(let i=0;i<p;i++) {
        freq[s.charCodeAt(i)-97]+=1;
    }
    let left="",right="";
    for(let i=0;i<26;i++) {
        if(freq[i]>0) {
            left+=String.fromCharCode(i+97).repeat(freq[i]);
            right=String.fromCharCode(i+97).repeat(freq[i])+right;
        }
    }
    const mid=s.length%2===1?s[p]:"";
    return left+mid+right;
};