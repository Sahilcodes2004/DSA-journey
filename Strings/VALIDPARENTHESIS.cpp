#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
 * PROBLEM: Valid Parentheses (LeetCode 20 - Easy)
 * * PATTERN: Stack-Based String Parsing
 * 1. Loop through the string character by character.
 * 2. If it's an opening bracket, push it onto the stack.
 * 3. If it's a closing bracket, check the top of the stack.
 * 4. If they form a valid pair, pop the top element. If not, it's invalid.
 * 5. At the end, a valid string will leave behind an empty stack.
 * * TIME COMPLEXITY: O(N) - We traverse the string exactly once.
 * SPACE COMPLEXITY: O(N) - In the worst case (e.g., "((((("), all chars go into the stack.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If it is an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it is a closing bracket
            else {
                // If stack is empty but we have a closing bracket, it's invalid
                if (st.empty()) return false;
                
                char top = st.top();
                
                // Check if it's a valid matching pair
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // It's a match! Remove the opening bracket from stack
                } else {
                    return false; // Mismatch found
                }
            }
        }
        
        // If the stack is empty at the end, all brackets were matched perfectly
        return st.empty();
    }
};

int main() {
    Solution sol;
    
    cout << "Test 1 (): " << (sol.isValid("()") ? "True" : "False") << " (Expected: True)" << endl;
    cout << "Test 2 ()[]{}: " << (sol.isValid("()[]{}") ? "True" : "False") << " (Expected: True)" << endl;
    cout << "Test 3 (]: " << (sol.isValid("(]") ? "True" : "False") << " (Expected: False)" << endl;
    cout << "Test 4 ([)]: " << (sol.isValid("([)]") ? "True" : "False") << " (Expected: False)" << endl;

    return 0;
}