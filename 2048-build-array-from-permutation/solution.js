/**
 * @param {number[]} nums
 * @return {number[]}
 */
var buildArray = function(nums) {
    let index=0;
    let result=[];
    for(let i=0;i<nums.length;i++){
        result[index]=nums[nums[i]];
        index++;
    }
    return result;
};
