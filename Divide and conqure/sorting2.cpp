// #include <iostream>
// #include <vector>
// #include <cstdlib>
//
// using std::vector;
// using std::swap;
//
// int partition2(vector<int> &a, int l, int r) {
//   int x = a[l];
//   int j = l;
//   for (int i = l + 1; i <= r; i++) {
//     if (a[i] <= x) {
//       j++;
//       swap(a[i], a[j]);
//     }
//   }
//   swap(a[l], a[j]);
//   return j;
// }
//
// void randomized_quick_sort(vector<int> &a, int l, int r) {
//   if (l >= r) {
//     return;
//   }
//
//   int k = l + rand() % (r - l + 1);
//   swap(a[l], a[k]);
//   int m = partition2(a, l, r);
//
//   randomized_quick_sort(a, l, m - 1);
//   randomized_quick_sort(a, m + 1, r);
// }

#include<bits/stdc++.h>
#include<vector>
#include<tuple>

using namespace std;

void print(std::vector<long long> v){
  for ( long long i : v )
      cout << i << ",";
  cout << "\n";
}

tuple <long long , long long> partition( vector<long long> &arr , long long low , long long high , long long n){
  long long pivot = arr[high];
  long long index = low - 1 , count = 0;
  std::vector<long long > v;
  // cout << "low : " << low << ", high:" << high  << "\n";
  // cout << "pivot:" << pivot << '\n';
  long long int i = low;
  while ( i < high ){
    // std::cout << "element:" << arr[i] << '\n';
    if ( arr[i] <= pivot ){
        ++index;
        if ( arr[i] == pivot ){
           v.push_back(index);
           count++;
        }

        swap( arr[i] , arr[index] );
     }
         // print(arr);

    i++;
  }
  swap( arr[index+1] , arr[high] );
  // print(arr);
  // print(v);
  // long long eq_index = index + 1;

    //swapping the equal elements
    // for ( long long i : v ){
    //   --index;
    //
    //   swap ( arr[index]  , arr[i] );
    // }
    i = 0;
    while ( i < v.size() ) {
      // std::cout << "index:" << index << ",i:" << v[i] << '\n';
      if ( v[i] <= index ){
          if( arr[index] != pivot ){
              swap ( arr[v[i]]  , arr[index] );
              i++;
              index--;
          }
          else{
            index--;
          }
      }
      else{
        i++;
      }

    }

  // print(arr);
  // cout << "index: " << index+1 << " , count:" << count  << "\n";
  // return index+1;
  return make_tuple(index+1 , count  );
}

void quick_sort(vector<long long> &arr , long long low, long long high , long long n){

    long long index , count ;
    // std::cout << "\n" << '\n';
    if( low < high){
        tie( index , count ) = partition( arr , low , high , n );
        quick_sort( arr , low , index - 1  , n );
        quick_sort( arr , index + 1 + count , high , n );
    }
    // else{
    //   // std::cout << "In else" << '\n';
    //   cout << "low : " << low << ", high:" << high  << "\n";
    // }

}

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  quick_sort(a, 0, n - 1 , n );
  for (long long i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
}
