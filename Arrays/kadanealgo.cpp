#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<=0){
                sum=0;
            }
        }
        return maxi;
        
    }
};
int main(){
    Solution obj;
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    int result=obj.maxSubArray(arr);
    cout<<"The maximum subarray sum is "<<result<<endl;
    return 0;
}