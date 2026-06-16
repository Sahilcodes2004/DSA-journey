#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals by their start times
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < intervals.size(); i++) {
            // If ans is empty or there is no overlap
            if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            // If there is an overlap, merge by updating the end time
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    
    // Example test case (You can change these values to test others)
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    cout << "--- Merge Intervals ---" << endl;
    cout << "Original Intervals: ";
    for(auto interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    // Call the function
    vector<vector<int>> mergedIntervals = obj.merge(intervals);
    
    cout << "Merged Intervals:   ";
    for(auto interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    
    return 0;
}