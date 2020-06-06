#include <iostream>
#include <vector>

using namespace std;

// long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//   long long number_of_inversions = 0;
//   if (right <= left + 1) return number_of_inversions;
//   size_t ave = left + (right - left) / 2;
//   number_of_inversions += get_number_of_inversions(a, b, left, ave);
//   number_of_inversions += get_number_of_inversions(a, b, ave, right);
//   //write your code here
//   return number_of_inversions;
// }

void print(vector<long long> v){

    for ( long long i : v){
      cout << i << ",";
    }
    cout << "\n";
}

long long merge( vector<long long> &arr , long long left , long long mid , long long right ){
    long long n1 = mid - left + 1;
    long long n2 = right - mid;
    vector<long long> arr1(n1) , arr2(n2);
    long long i , j , k , count;
    std::cerr << "in merge" << '\n';
    cout << left << "," << mid << "," << right << "\n";
    for (long long i = 0; i < n1; i++) {
      arr1[i] = arr[ left + i ];
    }
    for (long long i = 0; i < n2; i++) {
      arr2[i] = arr[ mid + 1 + i ];
    }
    print(arr1);
    print(arr2);
    i = 0 , j = 0 , k = left , count = 0;
    while ( i < n1 && j < n2) {
        if ( arr1[i] <= arr2[j] ){
          arr[k] = arr1[i];
          i++;
        }
        else{
          arr[k] = arr2[j];
          j++;
          count++;
        }
        k++;
    }
    while ( i < n1 ){
      arr[k] = arr1[i];
      i++;
      k++;
    }
    while ( j < n2 ){
      arr[ k ] = arr2[j];
      k++;
      j++;
    }

    print(arr);
    cout << "\n\n";
    return count;

}

long long mergeSort(vector<long long> &arr , long long left , long long right , long long count ){
    long long mid = (right + left) / 2;
    cout << left << "," << mid << "," << right << "\n";
    // long long count = 0;
    if ( right > left ){
      mergeSort( arr , left , mid , count );
      mergeSort( arr , mid + 1 , right , count);
      count += merge( arr , left , mid , right );
    }
    else{
      std::cout << "in else" << '\n';
    }
    return count;
}

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long count = 0;
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << "count:" << mergeSort(a, 0, a.size() - 1 , count ) << "\n";
  // print(a);
  // vector<int> b(a.size());
  // cout << mergeSort(a, 0, a.size()) << '\n';
}
