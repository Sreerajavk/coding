
#include<bits/stdc++.h>
using namespace std;

int main(){

    int sum , temp , ans=0;

    for (int i = 0; i < 3; i++)
    {
       sum = 0;
       for (int j = 0; j < 3; j++)
       {
           cin >> temp;
           sum += temp;
       }
       ans += abs(sum - 15);
       
    }
    cout << ans << endl;
    
}