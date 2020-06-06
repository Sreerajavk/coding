#include <iostream>
#include <cstring>
using namespace std;
using std::string;

int min(int a , int b , int c ){
  return min(min( a, b) , c );
}

// void print( int a[][] , int n , int m){
//   for (int i = 0; i <= n; i++) {
//     for (int j = 0; j <= m; j++) {
//       std::cout << a[i][j] << ',';
//     }
//     std::cout  << '\n';
//   }
// }

int edit_distance(const string &str1, const string &str2 , int n , int m) {

    // if( n == 0 )
    //     return m;
    // if ( m == 0 )
    //     return n;
    // if ( str1[n - 1] == str2[m -1])
    //     return edit_distance( str1 , str2 , n - 1 , m - 1 );
    //
    // return 1 + min( edit_distance(str1 , str2 , n  , m - 1  ),
    //                 edit_distance(str1 , str2 , n - 1 , m ),
    //                 edit_distance(str1 , str2 , n - 1 , m - 1)
    //               );

    int dist[n + 1][m + 1];
    int i , j;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= m; j++) {
        // std::cout << "i:" << i << ", j:" << j << '\n';
          if( i == 0 )
            dist[i][j] = j;
          else if( j == 0 )
              dist[i][j] = i;
          else if( str1[ i - 1 ] == str2[ j - 1 ])
              dist[i][j] = dist[ i - 1 ][ j - 1 ];
          else
              dist[i][j] = 1 + min( dist[ i ][ j - 1] ,
                                    dist[ i -1 ][ j ] ,
                                    dist[ i -1 ][ j - 1 ]
                                  );
      }
    }

    return dist[n][m];

}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2 , str1.length() , str2.length()) << std::endl;
  return 0;
}
