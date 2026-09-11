#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target element to be searched:";
    cin>>target;
    Solution obj;
    int indi=obj.search(arr,target);
    cout<<"The element is found at index:"<<indi;
    return 0;

}