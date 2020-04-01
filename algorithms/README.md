# Basic algorithms
c++ code of various alogiritms and it's variations are included in this section

## Nth Fibonacci Number - Various methods

### 1. Recursion
``` 
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
} 
```
### 2. Dynamic programming solution

``` 
int fib(int n) {
    int arr[n];
    arr[0]=0 , arr[1]=1;
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
} 
```
### 3. Direct formula for small values of 'n'

![Equation](eqn.png)