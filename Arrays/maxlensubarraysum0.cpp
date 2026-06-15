#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for max()

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& arr) {
        int maxlen = 0;
        int prefix_sum = 0;
        unordered_map<int, int> mpp; 
        
        for(int i = 0; i < arr.size(); i++) {
            prefix_sum += arr[i];
            
            // If the sum from the beginning is 0
            if(prefix_sum == 0) {
                maxlen = i + 1;
            }
            
            // If we've seen this prefix_sum before, a zero-sum subarray exists between them
            if(mpp.find(prefix_sum) != mpp.end()) {
                int len = i - mpp[prefix_sum];
                maxlen = max(maxlen, len);
            } 
            else {
                // Only store if it's the first time seeing it (to maximize length)
                mpp[prefix_sum] = i;
            }
        }
        return maxlen;
    }
};

int main() {
    Solution obj;
    int n;
    
    cout << "--- Max Length of Subarray with Sum 0 ---" << endl;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " space-separated integers:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = obj.maxLength(arr);
    cout << "\n[RESULT] Maximum length of subarray with sum 0 is: " << result << endl;
    
    return 0;
}