#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>arr={1,2,3,1,5,4,3,7};
    vector<vector<int>>sorto;
    int maxi=0;
    int maximum=arr[0];
    for(int i=1;i<arr.size();i++)
    {  if(maximum<arr[i]){
            maximum=arr[i];
            
        }
       
    }
    vector<int>frequ(maximum+1);
    for(int i=0;i<arr.size();i++)
    {
        frequ[arr[i]]++;
    }
    for(int i=0;i<=maximum;i++)

    { vector<int>temp;
        int x=frequ[i];
        if(x==0)
        {
            continue;
        }
        if(x==1)
        {
           temp.push_back(i);
        }
        else{
            while(x>=1)
            {
                temp.push_back(i);
                x--;
            }
        }
        sorto.push_back(temp);



    }
    for(int i=0;i<sorto.size();i++)
    {
        for(int j=0;j<sorto[i].size();j++)
        {
        cout<<sorto[i][j]<<" ";
        }
        cout<<endl;

    }


    return 0;
}