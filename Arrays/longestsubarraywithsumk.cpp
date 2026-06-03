#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxi=0;
        map<long long,int>mpp;
        long long prefix_sum=0;
        for(int i=0;i<arr.size();i++){
            prefix_sum+=arr[i];
            if(prefix_sum==k){
            maxi=max(maxi,i+1);
        }
         long long remaining=prefix_sum-k;
        if(mpp.find(remaining)!=mpp.end()){
            maxi=max(maxi,i-mpp[prefix_sum-k]);
        }
        if(mpp.find(prefix_sum)==mpp.end()){
            mpp[prefix_sum]=i;
        }
        }
        return maxi;
       
        // code here
        
    }
};
int main(){
   vector<int> arr={10,5,2,7,1,-10};
   int k=15;
   Solution obj;
   int result=obj.longestSubarray(arr,k);
   cout<<"The length of longest subarray with sum k is "<<result<<endl;
   return 0;

}