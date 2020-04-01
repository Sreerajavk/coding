#include <iostream>
#include <cassert>
#include<math.h>

//Task. Given an integer n, find the nth Fibonacci number Fn .
//Input Format. The input consists of a single integer n.
//Constraints. 0 ≤ n ≤ 45.
//Output Format. Output Fn .

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long double  fibonacci_fast(int n) {
    // write your code here
    // Direct formula for finding fiboacci for small values of n
    // Fn=⎣(((1+√5)/2)^n) / √5⎦
    long double ans = round((pow(((1+sqrt(5))/2) , n))/sqrt(5));
    return ans;
}


int main() {
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
