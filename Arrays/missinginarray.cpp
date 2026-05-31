#include<iostream>
using namespace std;
int missingNum(int *arr, int size) {
    // code here
    int total=(size+1)*(size+2)/2;
    int sum=0;
    
    for(int i=0;i<size;i++){
        sum+=arr[i];
        
    }
    return total-sum;
}
int main(){
    int arr[]={1,3,5,4};
    int len=sizeof(arr)/sizeof(arr[1]);

    int x=missingNum(arr,len);
    cout<<x;
}