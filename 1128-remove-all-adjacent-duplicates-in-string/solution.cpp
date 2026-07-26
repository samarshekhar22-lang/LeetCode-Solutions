class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        
        // 1. Destroy duplicates using the stack
        for (int i = 0; i < s.size(); i++) {
            if (!s1.empty() && s1.top() == s[i]) {
                s1.pop();
            } else {
                s1.push(s[i]);
            }
        }
        
        // 2. Build the final string from the stack
        string result = "";
        while (!s1.empty()) {
            result += s1.top();
            s1.pop();
        }
        
        // 3. Reverse it because the stack gave it to us backwards
        reverse(result.begin(), result.end());
        
        return result;
    }
};
