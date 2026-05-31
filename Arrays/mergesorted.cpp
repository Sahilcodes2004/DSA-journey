#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Author: Sameer Sharma
// Roll No: 2400320100974

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0;
        int j = 0;
        vector<int> result;
        
        while(i < a.size() && j < b.size()) {
            if(a[i] < b[j]) {
                if(result.size() == 0 || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            }
            else if(a[i] > b[j]) {
                if(result.size() == 0 || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            }
            else {
                if(result.size() == 0 || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++; 
                j++;
            }
        } 
        
        while(i < a.size()) {
            if(result.size() == 0 || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }
        
        while(j < b.size()) {
            if(result.size() == 0 || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }
        
        return result;
    }
};

int main() {
    Solution ob;
    
    // Sample Test Case
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b = {2, 3, 4, 4, 5, 11, 12};
    
    vector<int> ans = ob.findUnion(a, b);
    
    cout << "Union Array: ";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}