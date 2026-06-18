#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&nums,int start,int mid,int end){
vector<int>temp;
     mid=start+(end-start)/2;
    int i=start;int j=mid+1;
    int invcnt=0;
    while(i<=mid&&j<=end)
    {
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i]);
            i++;

        }
        else{
            temp.push_back(nums[j]);
            j++;
            invcnt++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(nums[j]);
        j++;
    }
    return invcnt;
}
int mergesort(vector<int>&nums,int start,int end)
{
    int mid=start+(end-start)/2;
    if(start<end){
  int leftinversion=mergesort(nums,start,mid);
  int rightinversion=mergesort(nums,mid+1,end);
  int inversion=merge(nums,start,mid,end);
  return leftinversion+rightinversion+inversion;
    }
    
  return 0;



}

int main()
{
    vector<int>nums={1,3,5,10,2,6,8,9};
    int inversions=mergesort(nums,0,nums.size()-1);
    cout<<inversions<<endl;
    return 0;
}