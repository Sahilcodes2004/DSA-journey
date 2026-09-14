#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<int>& arr, int day, int m, int k) {

        int bouquets = 0;
        int flowers = 0;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] <= day) {
                flowers++;

                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if(bloomDay.size() < (long long)m * k) {
            return -1;
        }

        int low = 1;
        int high = *max_element(
            bloomDay.begin(),
            bloomDay.end()
        );

        int ans = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(isPossible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};int main() {

    Solution s;

    vector<int> bloomDay = {1, 10, 3, 10, 2};

    int m = 3;
    int k = 1;

    cout << s.minDays(bloomDay, m, k);

    return 0;
}