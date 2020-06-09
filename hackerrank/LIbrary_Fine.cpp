
#include<bits/stdc++.h>
using namespace std;

int calculateFine(int d1 , int m1 , int y1 , int d2 , int m2 , int y2){


    if (y1 == y2){
        if(m1 == m2){
            if(d1 <= d2)
                return 0;
            return abs(d1 - d2) * 15;
        
        }
        else if(m1 > m2)
            return abs(m1 - m2 ) * 500;
        return 0;
    }
    else if(y1 > y2)
        return 10000;
    return 0;
        
}

int main(){
    int d1 , d2 , m1 , m2 , y1 , y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;

    cout << calculateFine(d1 , m1 , y1 , d2 , m2 , y2) << endl;
    return 0;
}