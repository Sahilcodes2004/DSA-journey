#include<iostream>
using namespace std;
int largest(int arr[],int n){
        
int maxi=arr[0];
    for(int i=1;i<n;i++){
        
        if(arr[i]>maxi){
            maxi=arr[i];
        }
   
    }
    return maxi;
}
int main(){
    int arr[]={2,700,6,5,4,24,109};
    int x=sizeof(arr)/sizeof(arr[1]);
    int max=largest(arr,x);
    cout<<max;

}