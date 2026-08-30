class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;
        for(int i=0;i<nums.size();i++){
            int leftValue=target-nums[i];
            if(store.find(leftValue)!=store.end()){
                return{store[leftValue],i};
            }
            store[nums[i]]=i;
        }
        return {};
    }
};