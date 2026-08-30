class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mp; // Stores {number, index}
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // If the complement exists in our map, we found our pair!
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i + 1}; // i + 1 for 167's 1-based index requirement
        }
        
        // Otherwise, store the current number and its 1-based index
        mp[nums[i]] = i + 1;
    }
    return {};
}
};