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
 
// void solve() {
// 	int n; cin >> n;
// 	vector<int> h(n), c(n);

// 	for (auto &it : h) cin >> it;

// 	for (auto i = 1; i < h.size(); ++i) {
// 		c[i] = abs(h[i] - h[i - 1]) + c[i - 1];
// 		if (i >= 2) {
// 			c[i] = min(c[i], abs(h[i] - h[i - 2]) + c[i - 2]);
// 		}
// 	}
// 	cout << c[n - 1];
// }

void solve() {
	int n; cin >> n;
	vector<int> h(3);
	vector<int> dp(3);

	cin >> h[0];
	for(auto i = 1; i < n; ++i) {
		auto cur = i % 3;
		auto p1 = (i - 1) % 3;
		auto p2 = (i - 2) % 3;

		cin >> h[cur];

		dp[cur] = abs(h[p1] - h[cur]) + dp[p1];
		if(i >= 2) {
			dp[cur] = min(dp[cur], abs(h[p2] - h[cur]) + dp[p2]);
		}
	}

	cout << dp[(n  - 1) % 3];
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
