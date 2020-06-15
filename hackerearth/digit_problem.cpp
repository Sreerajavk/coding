/*
Given two integers X and K, find the largest number that can be formed by changing digits at 
atmost K places in the number X.

Input:

First line of the input contains two integers X and K separated by a single space.

Output:

Print the largest number formed in a single line.

*/


#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
    string
     s;
    int k , index = 0 , i;
    cin >> s >> k;
    i=0;
    while (i < k)
    {
       if(s[index] != '9'){
           i++;
       }
       cout << "9";
       index++;
    }
    
    
    for(int i=index;i<s.length();i++)
        cout << s[i];


}