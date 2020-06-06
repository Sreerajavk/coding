#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int w,  vector<int> &weights) {
  //write your code here
  // int current_weight = 0;
  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  // return current_weight;
  int n = weights.size();
  vector<vector <int>> ans(n+1 ,vector<int>(w+1));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if( i == 0 || j == 0)
          ans[i][j] = 0;
      else if( weights[i - 1] <= j)
          ans[i][j] = max( ans[i - 1][j] , weights[i - 1] + ans[i - 1][j - weights[i - 1]]);
      else
          ans[i][j] = ans[i - 1][j];
      // std::cout << "i:" << i << ",j:" << j << '\n';
      // for (size_t l = 0; l <= n; l++) {
      //   for (size_t m = 0; m <= w; m++) {
      //     std::cout << ans[l][m] << ',';
      //   }
      //   std::cout  << "\n";
      // }

      // std::cout << "\n\n";
    }
  }
  return ans[n][w];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
