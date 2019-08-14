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


void walk (int u, vector<ll> & dist, 
	vector<vector<int>> & adj, vector<int> & inDeg) {

	for (auto v : adj[u]) {
		inDeg[v]--;
		dist[v] = max(dist[u] + 1l, dist[v]);
		if (inDeg[v] == 0) {
			walk(v, dist, adj, inDeg);
		}
	}
}

void solve () {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 2);
	vector<int> inDeg(n + 2);

	for (auto i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		inDeg[v]++;
	}

	vector<ll> dist(n + 2, -1);
	for (auto i = 1; i <= n; ++i) {
		if (inDeg[i] == 0 and dist[i] == -1) {
			dist[i] = max(dist[i], 0ll);
			walk(i, dist, adj, inDeg);
		}
	}

	ll ret = 0;
	for (auto it : dist) {
		ret = max(ret, it);
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
