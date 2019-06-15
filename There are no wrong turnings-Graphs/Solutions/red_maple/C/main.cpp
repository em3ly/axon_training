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
  int n, m; cin >> n >> m;

  vector<int> gold(n + 1);
  for(auto i = 1; i < (int)gold.size(); ++i) {
    cin >> gold[i];
  }

  vector<vector<int>> adj(n + 1);
  for(auto i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> parents(n + 1, -1);
  iota(parents.begin(), parents.end(), 0);

  vector<int> minGold = gold;
  vector<int> size(n + 1, 1);

  function<int(int)> getParent = [&](int u) -> int {
    if(u == parents[u]) return u;
    parents[u] = getParent(parents[u]);
    minGold[u] = min(minGold[u], gold[u]);
    return parents[u];
  };

  auto sameParent = [&](int u, int v) -> bool {
    auto uP = getParent(u);
    auto vP = getParent(v);
    return uP == vP;
  };

  auto join = [&](int u, int v) {
    auto uP = getParent(u);
    auto vP = getParent(v);

    if(size[uP] > size[vP]) {
      swap(uP, vP);
    }

    parents[uP] = vP;
    size[vP] += size[uP];
    gold[vP] = min(gold[uP], gold[vP]); 
  };

  for(auto u = 1; u <= n; ++u) {
      for(auto v : adj[u]) {
        if(sameParent(u, v)) continue;
        join(u, v);
      }
  }

  ll totGold = 0;
  for(auto i = 1; i <= n; ++i) {
    if(getParent(i) == i) {
      totGold += gold[i];
    }
  }

  cout << totGold;
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