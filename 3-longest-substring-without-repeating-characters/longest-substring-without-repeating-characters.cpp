class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> u1; // Key is char, value is index
        int maxLength = 0;
        int left = 0;  
        for (int right = 0; right < s.size(); right++) {
            char c = s[right]; // Avoid naming it 'i' to prevent shadowing the loop variable
            
            if (u1.find(c) != u1.end() && u1[c] >= left) {
                left = u1[c] + 1;
            }
            
            u1[c] = right;
            maxLength = max(maxLength, right - left + 1); // Fixed subtraction formula
        }
        return maxLength;
    }
};