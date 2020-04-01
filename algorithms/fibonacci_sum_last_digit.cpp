
#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

// Task. Given an integer n, find the last digit of the sum F0 + F1 + · · · + Fn .
// Input Format. The input consists of a single integer n.
// Constraints. 0 ≤ n ≤ 10 14 .
// Output Format. Output the last digit of F0 + F1 + · · · + Fn .

int get_fibonacci_sum_last_digit(long long n , int m) {
    if (n <= 1)
        return n;
    vector<int> arr;
    int period , i = 2 , rem;

    // Finding the pisano period by taking m as  10( need to find last digit )
    // Dividing large N with period and sum of the previous values.
    // Finally take the modulus of the sum
    
    arr.push_back(0);
    arr.push_back(1);
    while (true) {
      arr.push_back((arr[i-1] + arr[i-2]) % m );
      if( arr[i]==1 && arr[i-1] == 0 ){
          period = arr.size() - 2;
          break;
        }
        i++;
    }
    int sum = 0;
    rem = n % period;
    for (size_t i = 0; i <= rem; i++) {
      sum  = (sum + arr[i]) % 10;
    }
    return sum;

}

int main() {
    int m;
    long long n;
    cin >> n ;
    int c = get_fibonacci_sum_last_digit(n , 10);
    cout << c << '\n';
    }
