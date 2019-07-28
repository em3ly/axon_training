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
  
  int n, m, s; cin >> n >> m >> s;

  vector<vector<int>> adj(n + 1);
  vector<vector<int>> e;

  for (auto i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w;

    adj[u].push_back(e.size());
    e.push_back({u, v, w});
    adj[v].push_back(e.size());
    e.push_back({v, u, w});
  }

  int l; cin >> l;

  vector<ll> minD(n + 1, inf);
  minD[s] = 0l;

  set<vector<ll>> pq;
  pq.insert({0l, s});

  unordered_map<int, unordered_set<int>> nodes;
  while (!pq.empty()) {
    auto cur = *pq.begin();
    pq.erase(pq.begin());

    if (cur[0] > l) break;
    
    int u = cur[1];
    ll d = minD[u];

    for (auto c : adj[u]) {
      ll v = e[c][1];
      ll w = e[c][2];

      if (d < l and d + w > l) {
        nodes[u].insert(c);
      }

      if (d + w < minD[v]) {
        minD[v] = d + w;    
        pq.insert({minD[v], v});
      }
    }
  }


  ll cnt = 0; 
  for (auto i = 1; i < (int)minD.size(); ++i) {
    if (minD[i] == l) cnt++;
  }

  set<int> seen;
  for (auto p : nodes) {
    auto  u = p.first;
    for (auto ed : p.second) {
      auto v = e[ed][1];
      auto w = e[ed][2];

      if (seen.count(ed))continue;

       int du = l - minD[u];
       int dv = l - minD[v];

       if (minD[v] >= l) {
        cnt++;
      } else if (du + dv == w) {
        cnt++;
      } else if (du + dv < w) {
        cnt+= 2;
      }

      seen.insert(ed);
      seen.insert(ed ^ 1);
  
    }

  }
  cout << cnt; 
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