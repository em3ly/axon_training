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
 

void solve() {
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for (auto &it : h) cin >> it;

	vector<int> dp(n, 1e9 + 100);
	dp[0] = 0;

	for (auto i = 1; i < n; ++i) {
		for (int j = i - 1; j >= i - k and j >= 0; --j) {
			int a = abs(h[i] - h[j]);
			dp[i] = min(dp[i], a + dp[j]);
		}
	}

	cout << dp[n - 1];
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