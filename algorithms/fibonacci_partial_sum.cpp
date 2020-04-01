
#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

//Task. Given two non-negative integers m and n, where m ≤ n, find the last digit of the sum Fm + Fm+1 +· · · + Fn .
//Input Format. The input consists of two non-negative integers m and n separated by a space.
//Constraints. 0 ≤ m ≤ n ≤ 10^14 .
// Output Format. Output the last digit of Fm + Fm+1 + · · · + Fn .

int get_fibonacci_partial_sum( long long from , long long to ,  int m ) {

    vector<int> arr;
    // cout<<from << to;
    int period,i=2 , rem1 , rem2;

    // Finding the pisano period by taking m as  10( need to find last digit )
    // Finding the range by dividing both from and to with peroid
    // Take sum in the range and ouput modulo 10

    arr.push_back(0);
    arr.push_back(1);
    while (true) {
      arr.push_back( (arr[i-1] + arr[i-2]) % m );
      if( arr[i]==1 && arr[i-1]==0 ){
          period = arr.size()-2;
          break;
        }
        i++;
    }
    int sum = 0;
    // period -= 2;
    rem1 = from % period;
    rem2 = to % period;
    i = rem1;

    while( true ){

      if(i == period)  // looping from rem1 to rem2
        i = 0;           // when rem1 equals peroid start from 0 to rem2
      else
         sum  = (sum + arr[i]) % 10;
      if( i == rem2 )
        break;
      i++;
    }
    return sum;

}

int main() {
    int m;
    long long from , to;
    cin >> from >> to ;
    int c = get_fibonacci_partial_sum(from , to , 10);
    cout << c << '\n';
    }
