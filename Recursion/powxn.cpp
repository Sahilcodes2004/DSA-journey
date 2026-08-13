#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to avoid overflow when n = -2147483648
        long long nn = n;
        
        // If power is negative, make it positive for the calculation
        if (nn < 0) {
            nn = -nn;
        }
        
        double ans = 1.0;
        
        // Binary Exponentiation O(log N)
        while (nn > 0) {
            // If power is odd
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            } 
            // If power is even
            else {
                x = x * x;
                nn = nn / 2;
            }
        }
        
        // If the original power was negative, invert the answer
        if (n < 0) {
            ans = 1.0 / ans;
        }
        
        return ans;
    }
};

// Main function for local testing in VS Code
int main() {
    Solution sol;
    
    // Test Case 1: Positive power
    double x1 = 2.00000;
    int n1 = 10;
    cout << "Input: x = " << x1 << ", n = " << n1 << "\n";
    cout << "Output: " << sol.myPow(x1, n1) << " (Expected: 1024.0)\n\n";

    // Test Case 2: Power of 0
    double x2 = 2.10000;
    int n2 = 3;
    cout << "Input: x = " << x2 << ", n = " << n2 << "\n";
    cout << "Output: " << sol.myPow(x2, n2) << " (Expected: 9.2610)\n\n";

    // Test Case 3: Negative power
    double x3 = 2.00000;
    int n3 = -2;
    cout << "Input: x = " << x3 << ", n = " << n3 << "\n";
    cout << "Output: " << sol.myPow(x3, n3) << " (Expected: 0.25)\n\n";

    // Test Case 4: Extreme edge case (Min integer)
    double x4 = 2.00000;
    int n4 = -2147483648;
    cout << "Input: x = " << x4 << ", n = " << n4 << "\n";
    cout << "Output: " << sol.myPow(x4, n4) << " (Expected: 0.0)\n\n";

    return 0;
}