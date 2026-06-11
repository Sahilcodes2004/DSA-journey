#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int>ans;
        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(count1==0&&nums[i]!=ele2){
               count1=1;
               ele1=nums[i];
            }
            else if(count2==0 &&nums[i]!=ele1){
                count2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                count2++;
            }
        }
        int threshold=nums.size()/3+1;
        if(count1>=threshold){
            ans.push_back(ele1);

        }
        if(count2>=threshold){
            ans.push_back(ele2);

        }
       
        
        return ans;
        
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 1, 3, 2, 2, 1};
    vector<int>sol=obj.majorityElement(nums);
    for( auto x:sol){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;


}