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
// 	int n; cin >> n;
// 	vector<vector<int>> days(n, vector<int>(3));
// 	for (auto &it : days) {
// 		cin >> it[0] >> it[1] >> it[2];
// 	}

// 	vector<vector<int>> dp(n, vector<int>(3));
// 	dp[0] = days[0];

// 	for (auto i = 1; i < n; ++i) {
// 		dp[i][0] = days[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
// 		dp[i][1] = days[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
// 		dp[i][2] = days[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
// 	}

// 	int ret = max(dp[n - 1][0], dp[n - 1][1]);
// 	ret = max(ret, dp[n - 1][2]);
// 	cout << ret << endl;
// }

void solve () {
	int n; cin >> n;
	vector<int> days(3);
	vector<vector<int>> dp(2, vector<int>(3));

	for (auto &it : dp[0]) cin >> it;

	for (auto i = 1; i < n; ++i) {
		auto cur = i % 2;
		auto prev = (i - 1) % 2;

		cin >> days[0] >> days[1] >> days[2];
		dp[cur][0] = days[0] + max(dp[prev][1], dp[prev][2]);
		dp[cur][1] = days[1] + max(dp[prev][0], dp[prev][2]);
		dp[cur][2] = days[2] + max(dp[prev][0], dp[prev][1]);
	}

	int ind = (n - 1) % 2;
	int ret = max(dp[ind][0], dp[ind][1]);
	ret = max(ret, dp[ind][2]);
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
