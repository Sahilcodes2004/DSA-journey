#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
        int low=0;
        int high=0;
        while(high < nums.size()){
            if(nums[high]!=0){
                swap(nums[low], nums[high]);
                low++;high++;
            }
            else{
                high++;
            }
            
        }
        
    }
    int main(){
        vector<int>nums={2,0,3,0,1,0,2,3};
        moveZeroes(nums);
        for(int i=0; i<nums.size(); i++){
    cout << nums[i] << " ";
}
    }