class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return compute(expression, memo);
    }
    
private:
    vector<int> compute(string expression, unordered_map<string, vector<int>>& memo) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;
        
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            
            if (c == '+' || c == '-' || c == '*') {
                vector<int> leftResults = compute(expression.substr(0, i), memo);
                vector<int> rightResults = compute(expression.substr(i + 1), memo);
                
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (c == '+') {
                            result.push_back(left + right);
                        } else if (c == '-') {
                            result.push_back(left - right);
                        } else if (c == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }
        
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        
        memo[expression] = result;
        return result;
    }
};