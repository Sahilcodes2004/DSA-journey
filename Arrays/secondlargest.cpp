#include<iostream>
using namespace std;

int secondLargest(int arr[], int n){

    int maxi = arr[0];

    for(int i = 1; i < n; i++){

        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    int secondMax = -1;

    for(int i = 0; i < n; i++){

        if(arr[i] != maxi && arr[i] > secondMax){
            secondMax = arr[i];
        }
    }

    return secondMax;
}

int main(){

    int arr[] = {12,35,1,10,34,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = secondLargest(arr, n);

    cout << ans;
}