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

vector<ll> dfs(int u, int parent, vector<vector<int>> & adj) {
	ll white = 1;
	ll black = 0;
	for (auto v : adj[u]) {
		if (v == parent) continue;
		auto cur = dfs(v, u, adj);
		auto curWhite = cur[1];
		auto curBlack = cur[0];

		black = (curBlack * white) % lmodulo
			+ ((curWhite + curBlack) * black) % lmodulo;

		white = (white * curWhite) % lmodulo;
	}
	return {white, (white + black) % lmodulo};
}

void solve () {
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);

	for (auto i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto vRet = dfs(1, -1, adj);
	auto ret = (vRet[0] + vRet[1]) % lmodulo;
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
