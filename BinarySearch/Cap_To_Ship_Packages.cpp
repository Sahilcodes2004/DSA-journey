#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int daysreq(vector<int>& weights, int cap)
    {
        int day = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++)
        {
            if(load + weights[i] > cap)
            {
                day++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }

        return day;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());

        int high = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            high += weights[i];
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(daysreq(weights, mid) <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};
int main()
{
    Solution obj;

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int capacity = obj.shipWithinDays(weights, days);

    cout << capacity;

    return 0;
}