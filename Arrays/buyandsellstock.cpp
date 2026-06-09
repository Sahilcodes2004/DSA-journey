#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
     
        int maxprofit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minprice){
                minprice=prices[i];
            }
            int profit=prices[i]-minprice;
         maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
        
    }
};
int main(){
    Solution obj;
    vector<int>prices={7,1,5,3,6,4};
    int result=obj.maxProfit(prices);




     cout<<result<<endl;


    return 0;
}