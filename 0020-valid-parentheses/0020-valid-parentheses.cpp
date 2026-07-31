class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (char a : s) {
            if (a == '(' || a == '{' || a == '[') {
                stk.push(a);
            } else {
                if (stk.empty()) return false;

                char t = stk.top();

                if ((t == '(' && a == ')') ||
                    (t == '{' && a == '}') ||
                    (t == '[' && a == ']')) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return stk.empty();
    }
};