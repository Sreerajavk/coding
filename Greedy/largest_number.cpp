#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string largest_number(vector<string> a) {
  //write your code here
      int  min_length , current_length , next_length , max_length , j  , match = 0;
      string current , next , result = "" , temp;
      while ( a.empty() == false ) {

        int index = 0 , j , k ;
        current = a[index];
        for (int i = 1; i < a.size(); i++) {
          next = a[i];
          // if( current > next ){
          //   swap( current , next );
          //   swap( index , i );
          // }

          // cout << "current:" << current  << "\n";
          // cout << "next:" << next  << "\n";
          current_length = current.length();
          next_length = next.length();
          max_length = max( current_length , next_length );
          min_length = min( current_length , next_length);
          j = 0;
          k = 0;
          for (size_t l = 0; l <= max_length; l++) {
            if( next[k] > current[j] ){
                current = next;
                index = i;
                break;
              }
            else if( next[k] == current[j])
                match++;

            // cout << "match: " << match << "\n";

            if ( match == min_length && min_length != max_length){
              temp = min( current , next );
              if( temp == next ){
                current = next;
                index = i;
              }
              // index = lower_bound( a.begin() , a.end() , current ) - a.begin();
              break;
            }

            if( j+1 < current_length )
                j++;
            if( k+1 < next_length )
                k++;
          }
          // cout << "local maximum:" << current <<"\n";
        }
        // cout << "index:" << index << "\n\n\n";
        result += current;
        a.erase(a.begin() + index );
      }
      return result;

}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a) << endl;
}
