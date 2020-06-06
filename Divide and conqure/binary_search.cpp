#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace std;

/*
  Task. The goal in this code problem is to implement the binary search algorithm.
  Input Format. The first line of the input contains an integer n and a sequence a0 < a1 < . . . < an−1
      of n pairwise distinct positive integers in increasing order. The next line contains an integer k and k
      positive integers b 0 , b 1 , . . . , b k−1 .
  Constraints. 1 ≤ k ≤ 10 5 ; 1 ≤ n ≤ 3 · 10 4 ; 1 ≤ a i ≤ 10 9 for all 0 ≤ i < n; 1 ≤ b j ≤ 10 9 for all 0 ≤ j < k;
  Output Format. For all i from 0 to k − 1, output an index 0 ≤ j ≤ n − 1 such that a j = b i or −1 if there
      is no such index.
*/

int binary_search(const vector<long long> &a, long long left , long long right , long long x) {
  long long mid;
  if( left > right)
      return -1;
  mid = ( left + right ) / 2;
  // cout << "left:" << left << " , right:" << right << " mid:" << mid << "\n";
  if ( a[mid] == x )
      return mid;
  else if ( a[mid] > x )
      binary_search( a , left , mid -1 , x );
  else
      binary_search ( a , mid + 1 , right , x );

}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (long long i = 0; i < m; ++i) {
    std::cout << binary_search(a, 0 , n ,  b[i]) << " ";
  }
}
