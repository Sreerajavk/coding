
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void bin(string s , int n) 
{ 
    int i; 
    for (i = 1 << n -1; i > 0; i = i / 2) {
        cout << i << "\n";
        (n & i)? cout<<"1": cout<< "0"; 
    }
}
int main(void) 
{ 
   string s;
   cin  >> s;
   bin(s , s.length());

} 
