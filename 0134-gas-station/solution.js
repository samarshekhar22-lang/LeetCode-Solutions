/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    let totalGas=0;
    let currentGas=0;
    let index=0;
    for(let i=0;i<gas.length;i++){
        let diff=gas[i]-cost[i];
        totalGas+=diff;
        currentGas+=diff;
        if(currentGas<0){
            currentGas=0;
            index=i+1;
        }
    }
    if (totalGas<0){
        return -1;
    }
    return index;
};
