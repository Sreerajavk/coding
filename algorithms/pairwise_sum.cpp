#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


int main(){
    long long int n ,i,j,product;
    cin>>n;
    vector<long long int>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    // for(i=0;i<n;i++){
    //     cout<<arr[i];
    // }
    cout<<arr[n-2]*arr[n-1]<<endl;

    return 0;
}