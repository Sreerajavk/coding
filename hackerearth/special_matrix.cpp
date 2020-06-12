
#include<bits/stdc++.h>
using namespace std;

/*
You are given a square matrix of size n (it will be an odd integer). Rows are indexed 0 to n-1 
from top to bottom and columns are indexed 0 to n-1 form left to right. Matrix consists of only 
'*' and '.'. '*' appears only once in the matrix while all other positions are occupied by '.'

Your task is to convert this matrix to a special matrix by following any of two operations 
any number of times.

    1) you can swap any two adjecent rows, i and i+1 (0<= i < n-1)

    2) you can swap any two adjecent columns, j and j+1 (0<= j < n-1)

Special Matrix is one which contain '*' at middle of matrix. 


*/

int main(){

    int t , n  , x , y , mid;
    char temp;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        // cout << n << "\n";
        for(int j = 0; j < n; j++){
            for (int k = 0; k < n; k++) {
               cin >> temp;
               if(temp == '*'){
                    x = j;
                    y = k;
                    cout  << x << y << endl;
                }
            
            }
        }
        mid = n/2;
        cout << abs(mid -x ) + abs(mid -y) << endl;
    }
}