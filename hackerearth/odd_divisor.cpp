// /*
// You are given a positive integer N . f(N)is the greatest odd divisor of
// Find the sum (f(1) + f(2) + .. + f(N)) % M

// Input format

// The first line of the input contains a single integer T(No of test cases)
// The next line of each test case contains two integers N and M

// Output format

// For each output (f(1) + f(2) + .. + f(N)) % M

// */


// #include<bits/stdc++.h>
// #include<string.h>
// using namespace std;

// int solve_naive(int n , int m){
    
//     int sum = 0;
//     for(int i = 1; i <= n; i++){
//         if(i & 1 ){
//             // cout << i << endl;
//             sum += i;
//         }
//         else{
           
// 			int half= i/2;
//             // cout << half << endl;
// 			if(half % 2 == 0){
//                  for(int j = half -1 ; j>=1 ; j -=2){
//                     if(i % j ==0){
//                             // cout << i << "," << j << endl;
//                             sum += j;
//                             break;
//                     }
//             }
//             }
				
// 			else	
// 			 	sum += half;
//         }
//     }
//     return sum % m;
// }

// int solve1(long long n , long long m){

//     // long long ans[n+1] = {0};
//     // vector<long long> ans(n+1);
//     long long  sum = 0;
//     for(long long i = 1; i <= n; i++){
//             // cout << i << endl;
//             if(i & 1 ){
//                 // cout << "odd" << endl;
//                 // cout << i << endl;
//                 // ans[i] = i;
//                 sum += i;
//             }              
//             else{
//                 // // cout << "even" << endl;
//                 // // cout << ans[i/2] << endl;
//                 // ans[i] = ans[i/2];
//                 // sum += ans[i/2];
            
                
//                     for(long long j = i/2; j > 0; j = j / 2 ){
//                         if(j & 1 ){
//                             sum += (j);
//                             break;
//                         }

//                     }
//                     // while((i/2) > 0){
//                     //     cout << i / 2 << endl;
//                     //     if((i/2) % 2 !=0 ){
//                     //         sum += (i/2);
//                     //         break;
//                     //     }
//                     //      i  = i/2;
//                     // }
                
//             }
                
//     }

//     return sum% m;

// }

// int main(){

//     long long t , n , m;
//     cin >> t;
//     for (long long i = 0; i < t; i++)
//     {
//        cin >> n >> m;
//        cout << solve1(n , m) << endl;
//     }
    
// }


#include <bits/stdc++.h> 
using namespace std; 

long long square(long long n , long long m) {
        long long rem = n % m;
        // cout << rem * rem << endl;
        return (rem * rem) % m;
     } 


long long sum(long long n , long long m) 
{ 
    // cout << "n: " << n << endl;
	if (n == 0) 
		return 0; 
	if (n % 2 == 1) { // Odd n 
		return square((n + 1 ) / 2 , m) % m  + sum(n / 2 , m);	 
	} 
	else { // Even n 
		return square(n / 2 , m) % m + sum(n / 2 , m); 
	} 
} 

long long oddDivSum(long long  n , long long m) 
{ 
    // cout << sum(b) << endl;
	return sum(n , m);
}


int main() 
{ 
    long long t , n , m;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
       cin >> n >> m;
       cout << oddDivSum( n , m) %m << endl;
    }
} 

