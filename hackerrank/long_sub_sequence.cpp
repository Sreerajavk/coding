

#include <bits/stdc++.h>
#include <string.h>

using namespace std;

/*
   Find the longest common subsequence of given two strings
 */

int longestSubSequence(string s, string t)
{
	  int n = s.length();
	  int m = t.length();
	  int ans[n+1][m+1], i, j;

	  for(i = 0; i <= n; i++) {
			for(j = 0; j <= m; j++) {
				  if(i == 0 || j == 0)
						ans[i][j] = 0;

				  else if(s[i] == t[j])
						ans[i][j] = 1 + ans[i-1][j-1];
				  else
						ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
			}
	  }
	  return ans[n][m];
}

int main(){

	  string s, t;
	  cin >> s;
	  cin >> t;
	  cout << longestSubSequence(s,t) << endl;
	  return 0;
}
