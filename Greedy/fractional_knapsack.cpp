#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

void print(vector<float> v){
  cout << "\nfactor vector\n";
  for (size_t i = 0; i < v.size(); i++) {
  cout << v[i] << ",";
  }
  cout << "\n";
}
int findMaxIndex(vector<float> v){
  int temp = v[0];
  int pos = 0;
  for (size_t i = 1; i < v.size(); i++) {
    if( v[i] > temp )
        pos = i;
  }
  return pos;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0 , sum = 0.0;
  int n = weights.size()   , max , index;
  vector<float> factor(n);
  vector<float>::iterator index_pt;
  for (size_t i = 0; i < n; i++) {
      factor[i] = (float)values[i] / weights[i];
  }
  while (sum != capacity) {

      // print(factor);
      index  = findMaxIndex(factor);
      // cout << "index:" << index << "\n";
      // cout << factor[index] << "\n";
      // print(factor);
      if ( sum + weights[index] > capacity ){
        // cout << ((capacity - sum) / weights[index] * values[index])  << "\n";
        value = value + (((capacity-sum)/weights[index]) * values[index]);
        sum = capacity;
      }
      else{
        sum += weights[index];
        value += values[index];
    }
    factor.erase(factor.begin() + index);
    weights.erase(weights.begin() + index);
    values.erase(values.begin() + index);

      if(factor.size() == 0)
        break;

      // return sum;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  cout << fixed << setprecision(4) << optimal_value << endl;
  return 0;
}
