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
  int n, r1, r2; cin >> n >> r1 >> r2;

  vector<vector<int>> adj(n + 1);

  for (auto i = 1; i <= n; ++i) {
    if (i == r1) continue;
    int lastSeen;
    cin >> lastSeen;

    adj[i].push_back(lastSeen);
    adj[lastSeen].push_back(i);
  }

  vector<int> last(n + 1, -1);

  queue<int> q;
  last[r2] = r2;
  q.push(r2);

  while (!q.empty()) {
    auto u = q.front(); q.pop();

    for (auto v : adj[u]) {
      if (last[v] != -1) continue;
      last[v] = u;
      q.push(v);
    }
  }

  for (auto i = 1; i <= n; ++i) {
    if (i == r2) continue;
    cout << last[i] << " ";
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