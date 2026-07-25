class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        for(char i : s) {
            if(i == '(' || i == '{' || i == '[') {
                s1.push(i);
            } else {
                if(s1.empty()) {
                    return false;
                }
                char a = s1.top();
                if(i == ')' && a == '(') {
                    s1.pop();
                } else if(i == '}' && a == '{') {
                    s1.pop();
                } else if(i == ']' && a == '[') { // Fixed the single & here
                    s1.pop();
                } else {
                    return false;
                }
            }
        } // <-- The for loop officially ends here!
        
        return s1.empty(); // Now it checks the stack ONLY after the loop is done.
    }
};
