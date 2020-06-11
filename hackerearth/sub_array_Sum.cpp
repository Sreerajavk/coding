#include<bits/stdc++.h>
using namespace std;

/* 
Find whether consecutive subarray sum equal to given sum
*/

int solve(vector<int> arr , int n , int sum){

	int cum_sum1 = 0 , cum_sum2 = 0;
	for(int i = 0; i < n; i++){
		cum_sum1 += arr[i];
		cum_sum2 = 0;
		for(int j = 0; j <= i; j++){

			if(j != 0 )
				cum_sum2 += arr[j-1];
			if((cum_sum1 - cum_sum2) == sum)
				return 0;
		}
	}
	return -1;
}

int main(){
	int t , n , sum , cum_sum , temp;
	int arr[n];
	cin >> t;
	for(int i=0; i < t; i++){

		cin >> n >> sum;
		vector<int> arr1;
		for (int j=0; j < n; j++){
			cin >> temp;
			arr1.push_back(temp);
		}
			// cin >> arr[j];

		if(solve(arr1 , n , sum) == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}	
}
