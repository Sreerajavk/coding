#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
  Task. The goal in this code problem is to check whether an input sequence contains a majority element.
  Input Format. The first line contains an integer n, the next one contains a sequence of n non-negative
    integers a0 , a1 , . . . , an−1 .
  Constraints. 1 ≤ n ≤ 10^5 ; 0 ≤ a i ≤ 10^9 for all 0 ≤ i < n.
  Output Format. Output 1 if the sequence contains an element that appears strictly more than n/2 times,
    and 0 otherwise.
*/

int get_majority_element(vector<long long> &a) {

  sort(a.begin() , a.end());
  long long index = 0 , n = a.size() , count = 1;
  for (long long  i = 1; i < n; i++) {
     // cout << "index:" << index << " , i:" << i << ", count:" << count << "\n";
      if( a[index] == a[i] )
          count++;
      else{
          count = 1;
          index = i;
      }

      if ( count > n/2 )
          return 1;
  }
  return 0;

}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  cout << get_majority_element(a);
  // std::cout << (get_majority_element(a, 0, a.size()) << '\n';
  // for (long long i = 0; i < n; i++) {
  //   std::cout << get_majority_element(a , 0 , n  , a[i] );
  // }
}
