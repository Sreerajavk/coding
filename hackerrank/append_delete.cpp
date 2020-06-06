

#include <bits/stdc++.h>
#include <string.h>

using namespace std;


string solution(string s, string t, int k){

	  int count, n, i;
	  n = s.length() > t.length() ? t.length() : s.length();
	  std::cout << n << '\n';
	  for (i = 0; i < n; i++) {
			if(s[i] != t[i]) break;
	  }

	  std::cout << s.length() << "," << t.length() << "," << i << '\n';
	  count = s.length() + t.length() - ( 2 * i);
	  std::cout << count << '\n';

	  if(count > k)
			return "No";
	  else
			return "Yes";

}

int main(){
	  string s, t;
	  int k;

	  cin >> s;
	  cin >> t;
	  cin >> k;
	  cout << solution(s, t, k);
}
