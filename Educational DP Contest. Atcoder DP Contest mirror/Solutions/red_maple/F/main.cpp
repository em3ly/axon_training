#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;
 
const int precision = 3;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7
 
const double EPS = 1e-9;
const ll inf = 1e18;


void solve () {
	string s, t; cin >> s >> t;

	vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, 1e9));
	
	iota(dp[0].begin(), dp[0].end(), 0);
	for (auto i = 0; i < dp.size(); ++i) {
		dp[i][0] = i;
	}

	for (auto r = 1; r < dp.size(); ++r) {
		for (auto c = 1; c < dp[0].size(); ++c) {
			if(s[r - 1] == t[c - 1]) {
				dp[r][c] = dp[r- 1][c - 1];
			} else {
				dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + 1;
				dp[r][c] = min(dp[r][c], 1000000000);
			}
		}
	}

	string ret = "";

	int r = s.size();
	int c = t.size();

	while (r > 0 and c > 0) {
		if (s[r - 1] == t[c - 1]) {
			ret += s[r - 1];
			r--;
			c--;
		} else {
			if (dp[r - 1][c] < dp[r][c - 1]) {
				r--;
			} else {
				c--;
			}
		}
	}

	reverse(ret.begin(), ret.end());
	cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solve();
  return 0;
}

