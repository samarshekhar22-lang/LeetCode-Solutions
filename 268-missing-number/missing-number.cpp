class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int expectedSum=(size*(size+1))/2;
        int actualSum=0;
        for(int i=0;i<size;i++){
            actualSum+=nums[i];
        }
        int missingNumber=expectedSum-actualSum;
        return missingNumber;
    }
};