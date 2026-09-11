#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
long long totalhrs(vector<int>&piles,int hrs)
{
    long long totalhr=0;
    for(int i=0;i<piles.size();i++)
    {
        totalhr+=ceil(double(piles[i])/double(hrs));
    }
    return totalhr;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long  nhr=totalhrs(piles,mid);
            if(nhr<=h)
            {
                high=mid-1;
            }
            else{
              low=mid+1;
            }
        }
        return low;
        
        
    }
};
int main()
{ int n;
    cin>>n;
    Solution obj;
    vector<int>piles(n);
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>piles[i];
    }
    int h;
    cin>>h;
    
    int minihr=obj.minEatingSpeed(piles,h);
    cout<<"The minimum  integer such that koko can eat all bananas in hr hrs is:"<<minihr<<endl;

    return 0;
}