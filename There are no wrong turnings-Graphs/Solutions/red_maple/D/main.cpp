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
  int n; cin >> n;

  vector<vector<int>> adj(n + 1);
  map<vector<int>, int> roads;
  for(auto i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);

    if(u > v) swap(u, v);
    roads[{u, v}] = i;
  }

  vector<vector<vector<int>>> byDay(1);
  vector<int> seen(n + 1);

  function<void(int, int)> dfs = [&](int u, int day) {
    for(int i = 0, d = 0; i < (int)adj[u].size(); ++i) {
      auto v = adj[u][i];
      int uu = u, vv = v;
      if(uu > vv) swap(uu, vv);
      if(seen[roads[{uu, vv}]]) continue;
      if(d == day) d++;
      while((int)byDay.size() <= d) byDay.push_back({});
      seen[roads[{uu, vv}]] = true;
      byDay[d].push_back({uu, vv});
      dfs(v, d);
      d++;
      
    }
  };

  int first = 1;
  int maxSize = adj[first].size();
  for(auto i = 2; i <= n; ++i) {
    if(adj[i].size() > maxSize) {
      first = i;
      maxSize = adj[i].size();
    }
  }

  dfs(first, -1);

  cout << byDay.size() << endl;
  for(auto i = 0; i < (int)byDay.size(); ++i) {
    cout << byDay[i].size() << " ";
    for(auto j : byDay[i]) {
      cout << roads[j] << " ";
    }
    cout << endl;
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