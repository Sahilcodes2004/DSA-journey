#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>generaterow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    
    for(int col=1;col<row;col++)
    {
        ans*=(row-col);
        ans/=col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

    vector<vector<int>> generate(int numRows) {


vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
          ans.push_back(generaterow(i));
        }
        return ans;
        
    }
};
int main(){
    Solution obj;
    int rows;
    cin>>rows;

    vector<vector<int>>arr=obj.generate(rows);
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}