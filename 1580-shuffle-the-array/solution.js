/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function(nums, n) {
    let result=[];
    let index=0;
    for(let i=0;i<n;i++){
        result[index]=nums[i];
        index++;
        result[index]=nums[i+n];
        index++;
    }
    return result;
};
