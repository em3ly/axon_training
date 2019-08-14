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
	int n, m; cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	for (auto &r : grid) {
		for (auto &c : r) {
			cin >> c;
		}
	}

	vector<vector<ll>> dp(n , vector<ll>(m, 0));

	dp[0][0] = 1;
	for (auto r = 0; r < n; ++r) {
		for (auto c = 0; c < m; ++c) {
			if (r == 0 and c == 0) continue;
			if (grid[r][c] == '#') continue;
			dp[r][c] = r - 1 >= 0 ? dp[r - 1][c] : 0;
			dp[r][c] += c - 1 >= 0 ? dp[r][c - 1] : 0;
			dp[r][c] %= lmodulo;
		}
	}

	cout << dp[n - 1][m - 1];
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
