#include <iostream>
#include <vector>
#include<numeric>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum = 0 , current = 1 , array_sum , last , array_sum1;
  while( sum < n ){
    summands.push_back(current);
    sum += current;
      current++;
  }
  // return summands;
  array_sum = accumulate(summands.begin() , summands.end() , 0);
  if( array_sum == n )
      return summands;
  summands.pop_back();
  array_sum = accumulate(summands.begin() , summands.end() , 0);
  summands.pop_back();
  array_sum1 = accumulate(summands.begin() , summands.end() , 0);
  last = array_sum - array_sum1;
  summands.push_back( last + ( n - array_sum ));
  // while(true){
  //   if( sum + current + current + 1 <= n ){
  //     summands.push_back(current);
  //     sum = accumulate(summands.begin() , summands.end() , 0);
  //     current +=1;
  //   }
  //   else{0
  //     summands.pop_back();
  //     current++;
  //   }
  //   if(sum == n ){
  //     break;
  //   }
  // }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
