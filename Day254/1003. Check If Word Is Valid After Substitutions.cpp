class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        
        for (char c : s) {
            if (c == 'c') {
                if (stack.size() >= 2 && stack[stack.size() - 2] == 'a' && stack[stack.size() - 1] == 'b') {
                    stack.pop_back(); // remove b
                    stack.pop_back(); // remove a
                } else {
                    stack.push_back(c);
                }
            } else {
                stack.push_back(c);
            }
        }
        
        return stack.empty();
    }
};