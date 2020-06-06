#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#define INF 9999999;

using namespace std;

// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while (n >= 1) {
//     sequence.push_back(n);
//     if (n % 3 == 0) {
//       n /= 3;
//     } else if (n % 2 == 0) {
//       n /= 2;
//     } else {
//       n = n - 1;
//     }
//   }
//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }
int min(int a , int b , int c ){
  return min(min(a , b ) , c);
}
void print(vector<int> v){
  for( int i : v )
      cout << i << ",";
  cout  << '\n';
}


vector<int> solve( int n ){
    vector<int> min_ops(n+1);
    int min_value;
    min_ops[1] = 1;
    for (int i = 2; i <= n; i++) {

      // print(min_ops);
        int temp1 = INF;
        int temp2 = INF;
        int temp3 = INF;
        temp1 = min_ops[i - 1] + 1;
        if(i % 2 == 0 ) temp2 = min_ops[ i / 2 ] + 1;
        if(i % 3 == 0 ) temp3 = min_ops[ i / 3 ] + 1;
        min_value = min( temp1 , temp2 , temp3 );
        min_ops[i] = min_value;
    }
    std::cout << min_ops[n] - 1 << '\n';
    std::vector<int> values;
    while (n != 1) {
      values.push_back(n);
      if( n % 3 == 0 && min_ops[n] - 1 == min_ops[n / 3])
          n /= 3;
      else if( n % 2 == 0 && min_ops[n] - 1 == min_ops[n / 2])
          n /= 2;
      else
          n -= 1;
    }
    values.push_back(1);
    reverse(values.begin() , values.end());
    return values;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = solve(n);
  // std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
