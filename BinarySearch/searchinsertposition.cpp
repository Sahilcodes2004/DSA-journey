#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                high=mid-1;
            }
           
            else{
                low=mid+1;
            }
        }
        return  low;
        
    }
};
int main()
{
     int n;
     cin>>n;
     vector<int>nums(n);
     cout<<"Enter the elements of the array:";
     for(int i =0;i<n;i++)
     {
        cin>>nums[i];
     }
     int target;
     cout<<"Enter the element whose position is to be found:";
     cin>>target;
     Solution obj;
     
     int pos=obj.searchInsert(nums,target);
     cout<<"Element can be inserted at the position:"<<pos;
    return 0;
}