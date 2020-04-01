
#include <iostream>
#include<vector>
using namespace std;

//Task. Compute the last digit of F0^2 + F1^2 + · · · + Fn^2 .
//Input Format. Integer n.
//Constraints. 0 ≤ n ≤ 10^14 .
//Output Format. The last digit of F0^2 + F1^2 + · · · + Fn^2 .

int get_fibonacci_sum_square(long long n ,   int m) {
    if( n <= 1 )
        return n;
    vector<int> arr = { 0 , 1 };
    int period,i=2 , rem1 , rem2;

    // Finding the pisano period by taking m as  10( need to find last digit )
    // F0^2 + F1^2 + · · · + Fm^2 = Fm * Fm+1
    
    while( true ) {
      arr.push_back( (arr[i-1] + arr[i-2]) % m );
      if( arr[i]==1 && arr[i-1] == 0 ){
          period = arr.size()-2;
          break;
        }
        i++;
    }
    int sum = 0;
    rem1 = n % period;
    return( (arr[rem1] * arr[rem1 + 1]) % 10 ); // multiply Fn and Fn+1

}

int main() {
    int m;
    long long n;
    std::cin >> n;
    int c = get_fibonacci_sum_square(n, 10);
    std::cout << c << '\n';
    }
