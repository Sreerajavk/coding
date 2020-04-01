#include <iostream>
using namespace std;
//Task. Given two integers a and b, find their greatest common divisor.
//Input Format. The two integers a, b are given in the same line separated by space.
//Constraints. 1 ≤ a, b ≤ 2 · 10^9 .
//Output Format. Output GCD(a, b).

int gcd(int a, int b) {

  // using eucliedean algorithm to find the gcd
  // gcd(a,b)={ a            if b=0
  //          { gcd(b,a mod b) otherwise
  if(b==0)
    return a;
  else
    return gcd(b , a % b);

}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
