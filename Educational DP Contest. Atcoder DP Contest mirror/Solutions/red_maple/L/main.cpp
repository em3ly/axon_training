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


void solve () {
	int n; cin >> n;

	vector<ll> v(n);
	for (auto &it : v) cin >> it; 

	vector<vector<ll>> memo(n, vector<ll>(n, -1));
	function<ll(int, int)> getXY = [&](int l, int r) ->ll {
		if (l > r) return 0;
		if (l == r) return v[l];
		if(memo[l][r] != -1) return memo[l][r];

		ll ret = v[l] - getXY(l + 1, r);
		ret = max(ret, v[r] - getXY(l, r - 1));

		memo[l][r] = ret;
		return ret;
	};

	auto x = getXY(0, v.size() - 1);
	cout << x;
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