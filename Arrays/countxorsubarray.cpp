#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
        int running_xor = 0;
        unordered_map<int, int> mpp;
        
        // Base case: A prefix XOR of 0 happens 1 time by default
        mpp[0] = 1; 
        
        for(int i = 0; i < arr.size(); i++) {
            running_xor = running_xor ^ arr[i];
            int target_to_find = running_xor ^ k;
            
            if(mpp.find(target_to_find) != mpp.end()) {
                count += mpp[target_to_find];
            }
            
            mpp[running_xor]++;
        }
        return count;
    }
};

int main() {
    Solution obj;
    int n, k;
    
    cout << "--- Count Subarrays with XOR equals K ---" << endl;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " space-separated integers:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the target XOR value (K): ";
    cin >> k;
    
    long result = obj.subarrayXor(arr, k);
    cout << "\n[RESULT] Total number of valid subarrays: " << result << endl;
    
    return 0;
}