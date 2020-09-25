#include<bits/stdc++.h>
using namespace std;

int main() {

    int t , n , c , sum , temp;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        cin >> c;
        sum = 0;
        for ( int j=0; j<n; j++) {
            cin >> temp;
            sum += temp;
        }
        if(sum <= c ) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;

}