class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // 1. Declare count at the top so it doesn't reset!
        int count = 0; 
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                
                // 2. Use abs() to get the absolute difference
                if(abs(nums[i] - nums[j]) == k){
                    // 3. Added the missing semicolon
                    count++; 
                }
                
            }
        }
        
        return count;
    }
};
