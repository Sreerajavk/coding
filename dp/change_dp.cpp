#include <bits/stdc++.h>
#define INF 9999;
using namespace std;

void print(std::vector<int> v){
  for( int i : v )
      std::cout << i << ',';
  std::cout << '\n';
}

int get_change(int m , vector<int> &values) {

  int coins[] = { 1 , 3 , 4 };
  for(int i = 1; i <= m; i++) {
    values[i] = INF;
    for( int coin : coins ){
      if( i - coin >= 0 ){
          values[i] = min(values[i] , values [i - coin] + 1);
          // std::cout << "i:" << i << ",value:" << values[i] << '\n';
      }
    }
  }
  // print(values);
  return values[m];

  //write your code here
  // return m / 4;
  // int coins[] = { 1 , 3 , 4 };
  // if ( m == 0 )
  //     return 0;
  // if ( values[m] != -1 )
  //     return values[m];
  //
  // int best = INF;
  //
  // for( int coin : coins ){
  //   if( m - coin >= 0 ){
  //     best = min( best , get_change( m - coin , values) + 1);
  //   }
  // }
  //   // print( values );
  // values[m] = best;
  // return values[m];
}

int main() {
  int m;
  cin >> m;
  vector<int> values(m+1);
  // for (size_t i = 0; i <= m; i++) {
  //   values[i] = -1;
  // }
  values[0] = 0;
  cout << get_change(m , values) << '\n';
}
