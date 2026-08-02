class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m1;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        for(auto&i:m1){
            if(i.second>nums.size()/2){
                 return i.first;
            }
        }
        return -1;
    }
};
