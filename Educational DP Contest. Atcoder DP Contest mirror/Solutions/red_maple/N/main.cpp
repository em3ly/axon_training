#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>
#include <sys/resource.h>
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;
 
const int precision = 15;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7
 
const double EPS = 1e-9;
const ll inf = 1e18;


void increaseStack() {
	const rlim_t kStackSize = 50 * 1024 * 1024;   // min stack size = 50 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0) {
		if (rl.rlim_cur < kStackSize) {
			rl.rlim_cur = kStackSize;
		    result = setrlimit(RLIMIT_STACK, &rl);
		    if (result != 0) {
		    	fprintf(stderr, "setrlimit returned result = %d\n", result);
		    }
		}
	}
}


ll rec(int l, int r,  vector<int> & values, vector<vector<ll>> & memo) {
	if (l >= r) return 0;
	if (r - l == 1) return values[l] + values[r];
	if (memo[l][r] != -1) return memo[l][r];
	
	ll acc = inf;
	ll curAcc = accumulate(values.begin() + l, values.begin() + r + 1, 0l); 
	for (auto k = l; k < r; ++k) {
		acc = min(acc, rec(l, k, values, memo) + rec(k + 1, r, values, memo));
	}
	acc += curAcc;
	memo[l][r] = acc;
	return acc;
}

void solve_rec() {
	int n; cin >> n;
	vector<int> values(n);
	for (auto &it : values) cin >> it;

	vector<vector<ll>> memo(n + 1, vector<ll>(n + 1, -1));
	ll ret = rec(0, values.size() - 1, values, memo);
	cout << ret;
}

void solve() {
	int n; cin >> n;
	vector<ll> values(n);
	for (auto &it : values) cin >> it;

	vector<ll> accValues = values;
	for (auto i = 1; i < accValues.size(); ++i) {
		accValues[i] += accValues[i - 1];
	} 

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, inf));

	for (auto i = 0; i < n; ++i) {
		dp[i][i] = 0;
	}

	for (auto d = 1; d < n; ++d) {
		for (auto l = 0; l + d < n; ++l) {
			auto r = l + d;

			ll curAcc = accValues[r];
			curAcc -= l - 1 >= 0 ? accValues[l - 1] : 0;
			for (auto k = l; k < r; ++k) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + curAcc);
			}
		}
	}

	cout << dp[0][n - 1];
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
