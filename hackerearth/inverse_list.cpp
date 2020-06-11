
#include<bits/stdc++.h>
using namespace std;

/*
    A list is inverse list if position of i is the ith number in the list.
    find the given list is inverse or not

*/

int solve(vector<int> arr , int n){
    for (int j = 0; j < n; j++){
            if (arr[arr[j]-1] != j +1)
                return -1;
    }
    return 0;
}

int main(){

    int t , n  , temp;
    cin >> t;
    for ( int i = 0; i < t; i++){
        vector<int> arr;
        cin >> n;
        for (int j = 0; j < n; j++){
           cin >> temp;
           arr.push_back(temp); 
        }
        if(solve(arr , n) == -1)
            cout << "not inverse\n";
        else
            cout << "inverse\n";
    }
    return 0;
}