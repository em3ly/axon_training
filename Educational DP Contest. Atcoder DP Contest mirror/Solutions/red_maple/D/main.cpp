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

// void solve () {
// 	int n, W; cin >> n >> W;
// 	vector<vector<ll>> dp(n + 1, vector<ll>(W + 1));

// 	for (auto i = 1; i <= n; ++i) {
// 		int cw, v; cin >> cw >> v;
// 		for (int w = W; w >= 0; --w) {
// 			dp[i][w] = dp[i - 1][w];
// 			if(w - cw >= 0)
// 				dp[i][w] = max(dp[i][w], v + dp[i - 1][w - cw]);
// 		} 
// 	}
// 	cout << dp[n][W] << endl;
// }

void solve () {
	int n, W; cin >> n >> W;
	vector<vector<ll>> dp(2, vector<ll>(W + 1));

	for (auto i = 1; i <= n; ++i) {
		int cw, v; cin >> cw >> v;
		auto & cur = dp[i % 2];
		const auto & prev = dp[(i - 1) % 2];
		for (int w = W; w >= 0; --w) {
			cur[w] = prev[w];
			if(w - cw >= 0) {
				cur[w] = max(cur[w], v + prev[w - cw]);
			}
		}
	}

	cout << dp[n % 2][W];
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

