#include <iostream>
using namespace std;
//Task. Given two integers a and b, find their least common multiple.
//Input Format. The two integers a and b are given in the same line separated by space.
//Constraints. 1 ≤ a, b ≤ 10^7 .
//Output Format. Output the least common multiple of a and b.

int gcd(long  a, long b) {

  //By eucliedean formula
  // lcm(a , b) = (a * b) / gcd(a , b)
  if(b==0)
    return a;
  else
    return gcd(b , a%b);

}

int main() {
  long long  a, b;
  cin >> a >> b;
  cout << (a * b) / gcd(a , b) << endl;
  return 0;
}
