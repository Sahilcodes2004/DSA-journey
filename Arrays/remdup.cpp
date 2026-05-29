#include<iostream>
using namespace std;
#include<vector>
int removeDuplicates(vector<int>& nums) {
        
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
    int main(){
        vector<int>nums={2,2,3,3,3,4,4,4,4,5,5,6,6,6,6,};
       int x= removeDuplicates(nums);
       cout<<x;
    }