class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v1;
        for(int i=0;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            v1.push_back(nums[i]);
        }
        return v1;
    }
};     
