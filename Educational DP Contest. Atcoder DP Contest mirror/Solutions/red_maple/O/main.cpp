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


void solve() {
	int n; cin >> n;

	vector<vector<int>> match(n ,vector<int>(n));

	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < n; ++j) {
			cin >> match[i][j];
		}
	}

	vector<ll> dp (1 << n);
	dp[0] = 1;

	for (auto mask = 0; mask < (1 << n) - 1; ++mask) {
		auto m = __builtin_popcount(mask); 
		for (auto w = 0; w < n; ++w) {
			if (match[m][w] and !(mask & (1 << w))) {
				auto nextMask =  mask ^ (1 << w);
				dp[nextMask] += dp[mask];
				dp[nextMask] %= lmodulo;
			}	
		}
	}

	 cout << dp[(1 << n) - 1];
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
