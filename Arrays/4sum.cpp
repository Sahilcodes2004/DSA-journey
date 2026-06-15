#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum==target){
                        vector<int >temp={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(temp);
                        left++;
                        right--;
                        while(left<right &&nums[left]==nums[left-1]){
                            left++;
                        }
                        while(left<right&&nums[right]==nums[right+1]){
                            right--;
                        }

                    }
                    else if(sum>target){
                        right--;
                    }
                    else if(sum<target){
                        left++;
                    }
                }
            }
        
        }
        return ans;

       

}

};
int main() 
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution obj;
    
    // FIX 3: Declare and get the target BEFORE calling the function
    int target;
    cout << "Enter the Target: ";
    cin >> target; 
    
    // Now call the function
    vector<vector<int>> ans = obj.fourSum(nums,target);

    for(auto quad : ans){
        for(auto num : quad){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}