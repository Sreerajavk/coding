
#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

//Task. Given two integers n and m, output Fn mod m (that is, the remainder of Fn when divided by m).
//Input Format. The input consists of two integers n and m given on the same line (separated by a space).
//Constraints. 1 ≤ n ≤ 10^14 , 2 ≤ m ≤ 10^3 .
//Output Format. Output Fn mod m.

int get_fibonacci_huge_fast(long long n , int m) {
    if (n <= 1)
        return n;
    vector<int> arr;
    int period,i=2 , rem;

    //  Finding the pisano period where Fn mod m repeats after a pattern
    //  Pisano period always starts with 01
    //  Find the period size and divide it with large N.
    
    arr.push_back(0);
    arr.push_back(1);
    while (true) {
      arr.push_back((arr[i-1] + arr[i-2]) % m);
      if(arr[i]==1 && arr[i-1]==0){
          period = arr.size()-2; //excluding last 0 and 1
          break;
        }
        i++;
    }
    rem = n % period;
    return arr[rem];

}

int main() {
    int m;
    long long n;
    cin >> n >> m;
    int c = get_fibonacci_huge_fast(n,m);
    cout << c << '\n';
    }
