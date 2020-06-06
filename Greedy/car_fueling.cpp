#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int d, int tank, vector<int> & stops) {
    // write your code here
    int sum = 0 , i = 0 , distance , fuel_count = 0;
    while ( i < stops.size()-1 ) {
        distance = stops[i+1] - stops[i];
        if (distance > tank )
          return -1;
        sum += distance;
        if ( sum <= tank ){
          i+=1;
        }
        else{
            fuel_count +=1;
            sum = 0;
        }
    }
    return fuel_count;
}


int main() {
    int d , m , n;
    cin >> d;
    cin >> m;
    cin >> n;
    // cout << d << m << n << "\n";

    vector<int> stops(n+2);
    stops[0] = 0;
    for (size_t i = 1; i <= n; ++i){
      cin >> stops[i];
    }
    stops[n+1] = d;
    cout << compute_min_refills(d, m, stops) << "\n";
    return 0;
}
