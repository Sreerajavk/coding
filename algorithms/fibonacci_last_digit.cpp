#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

//Task. Given an integer n, find the last digit of the nth Fibonacci number Fn (that is, F n mod 10).
//Input Format. The input consists of a single integer n.
//Constraints. 0 ≤ n ≤ 10^7 .
//Output Format. Output the last digit of Fn .

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;
    vector<int> arr(n);
    // Using dynamic programming ie , storing previous resulst in a vector
    arr[0] = 0;
    arr[1] = 1;
    for (size_t i = 2; i <= n; i++) {
      arr[i] = (arr[i-1] + arr[i-2]) % 10;
    }
    return arr[n];

}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';
    }
