#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& nums) {

    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++) {

        // Count number of order breaks
        // (i+1)%n is used for circular traversal

        if(nums[i] > nums[(i+1)%n]) {
            count++;
        }
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)

    return count <= 1;
}

int main() {

    vector<int> nums = {1,3,4,0};

    cout << check(nums);
}