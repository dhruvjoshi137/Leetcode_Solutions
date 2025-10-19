#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int n = sizeof(arr)/sizeof(int);
    int val = 20;
    int j =0;
    for(int i=0;i<n;i++){
        if(arr[i]!=val){
            arr[j] = arr[i];

        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;

    }
    return 0;
}