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

void rec_solve () {
	increaseStack();

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) cin >> it;

	vector<int>memo(k + 1, -1);

	memo[0] = 0;
	function<bool(int)> won = [&](int cur) -> bool {
		if(cur == 0) {
			return false;
		}

		if (memo[cur] != -1)  return memo[cur];

		for (auto i : a) {
			if ((cur - i) < 0) continue;
			if (!won(cur - i)) {
				memo[cur] = 1;
				return true;
			}
		}
		memo[cur] = false;
		return false;
	};

	if (won(k)) {
		cout << "First";
	} else {
		cout << "Second";
	}
}

void solve () {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &it : a) cin >> it;
		
	vector<int> dp(k + 1);
	dp[0] = 0;
	for (auto i = 1; i <= k; ++i) {
		for (auto v : a) {
			if(i - v >= 0 and dp[i - v] == 0) {
				dp[i] = 1;
				break;
			}
		}
	}

	if (dp[k] == 1) {
		cout << "First";
	} else {
		cout << "Second";
	}
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
