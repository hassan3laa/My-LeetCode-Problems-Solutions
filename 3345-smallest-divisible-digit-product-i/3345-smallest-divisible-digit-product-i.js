/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {
    const check=(x)=>{
        let ans=1;
        while(x){
            ans*=x%10;
            x=Math.floor(x/10);
        }
        return ans;
    }
    for(let i=n;i<=100;i++){
        const x=check(i);
        if(x%t==0) {
            return i;
        }
    }
};