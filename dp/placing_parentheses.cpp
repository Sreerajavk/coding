#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include<algorithm>
#include<limits>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}


// tuple<long long , long long>minAndMax()


long long get_maximum_value(const string &exp) {
  //write your code here
  vector<long long>operents;
  vector<char>operators;
  for( char i : exp ){
    if( i == '+' || i == '-' || i == '*')
        operators.push_back(i);
    else
        operents.push_back(i - '0');
  }
  long long n = operents.size();
  // std::cout << "length:" << n << '\n';
  // for( long long i : operents )
  //       std::cout << i << ',';
  // std::cout  << '\n';
  vector<vector<long long>> m(n  , vector<long long>(n ));
  vector<vector<long long>> M(n  , vector<long long>(n ));
  for (long long i = 0; i < n; i++) {
    m[i][i] = operents[i];
    M[i][i] = operents[i];
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < n - i; j++) {
        // std::cout << j << "," << i+j << '\n';
        // tie(m[j][i+j] , M[j][i+j]) = minAndMax(M , m , i , j , operators);

        long long min_value = numeric_limits<long long>::min();
        long long max_value = numeric_limits<long long>::max();
        vector<long long>values(6);
        values[0] = min_value;
        values[5] = max_value;
        for (long long k = j; k < i + j; k++) {
          values[1] = eval(m[j][k] , m[k+1][i+j] , operators[k]);
          values[2] = eval(m[j][k] , M[k+1][i+j] , operators[k]);
          values[3] = eval(M[j][k] , m[k+1][i+j] , operators[k]);
          values[4] = eval(M[j][k] , M[k+1][i+j] , operators[k]);
          sort(values.begin() , values.end());
          if( k == j ){
              values[0] = values[1];
              values[5] = values[4];
            }
            // for( long long el : values)
            //     std::cout << el << ',';
            // std::cout  << '\n';
        }
        m[j][i+j] = values[0];
        M[j][i+j] = values[5];

        // std::cout << "min matrix" << '\n';
        // for (long long l = 0; l < n; l++) {
        //   for (long long o = 0; o < n; o++) {
        //     std::cout << m[l][o] << ',';
        //   }
        //   std::cout  << '\n';
        // }
        // std::cout << "max matrix" << '\n';
        // for (long long l = 0; l < n; l++) {
        //   for (long long o = 0; o < n; o++) {
        //     std::cout << M[l][o] << ',';
        //   }
        //   std::cout  << '\n';
        // }
        //
        // std::cout  << "\n\n";

    }
  }
  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
