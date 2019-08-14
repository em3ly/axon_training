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
// 	int n, W;  cin >> n >> W;
// 	vector<int> weight(n), value(n);
	
// 	for (auto i = 0; i < n; ++i) {
// 		cin >> weight[i] >> value[i];
// 	}

// 	int maxVal = accumulate(value.begin(), value.end(), 0);

// 	vector<vector<ll>> dp(weight.size() + 1, vector<ll>(maxVal + 1, inf));
// 	dp[0][0] = 0;

// 	for (auto i = 1; i < dp.size(); ++i) {
// 		const auto & w = weight[i - 1];
// 		const auto & cv = value[i - 1];
// 		for (int v = maxVal; v >= 0; --v) {
// 			dp[i][v] = dp[i - 1][v];
// 			if (v - cv >= 0) {
// 				dp[i][v] = min(dp[i][v], dp[i - 1][v - cv] + w);
// 			}
// 		}
// 	}

// 	int ret = 0;
// 	for (int i = 0; i<= maxVal; ++i) {
// 		if(dp[n][i] <= W) {
// 			ret = max(ret, i);
// 		}
// 	}
// 	cout << ret;
// }

void solve () {
	int n, W;  cin >> n >> W;
	vector<int> weight(n), value(n);
	
	for (auto i = 0; i < n; ++i) {
		cin >> weight[i] >> value[i];
	}

	int maxVal = accumulate(value.begin(), value.end(), 0);

	vector<vector<ll>> dp(2, vector<ll>(maxVal + 1, inf));
	dp[0][0] = 0;

	for (auto i = 1; i <= n; ++i) {
		const auto & w = weight[i - 1];
		const auto & cv = value[i - 1];
		auto cur = i % 2;
		auto prev = (i - 1) % 2;
		for (int v = maxVal; v >= 0; --v) {
			dp[cur][v] = dp[prev][v];
			if (v - cv >= 0) {
				dp[cur][v] = min(dp[cur][v], dp[prev][v - cv] + w);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i<= maxVal; ++i) {
		if(dp[n % 2][i] <= W) {
			ret = max(ret, i);
		}
	}
	cout << ret;
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

