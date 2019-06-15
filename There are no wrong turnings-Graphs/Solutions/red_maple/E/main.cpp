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
  int n, x; cin >> n >> x;

  vector<vector<int>> adj(n + 1);
  for(auto i = 1; i  < n; ++i) {
    int u, v; cin >> u >> v;
    if(u > v) swap(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
vector<vector<int>> d(n + 1, vector<int>(2, -1));

auto dist = [&](int init, int ind) -> void {
  vector<int> seen(n + 1, false);
  seen[init] = true;
  d[init][ind] = 0;

  queue<int> q, h;
  q.push(init);
  h.push(0);

  while(!q.empty()) {
    auto u = q.front(); q.pop();
    auto hu = h.front(); h.pop();
    d[u][ind] = hu;

    for(auto v : adj[u]) {
      if(seen[v]) continue;
      seen[v] = true;
      q.push(v);
      h.push(hu + 1); 
    }
  }
};  

  dist(1, 0);
  dist(x, 1);

  vector<int> seen(n + 1, false);
  int maxD = 0;
  function<void (int)> dfs = [&](int u) -> void{
    for(auto v : adj[u]) {
      if(seen[v]) continue;
      if(d[v][0] > d[v][1]){
        maxD = max(maxD, d[v][0]);  
      }
      seen[v] = true;
      dfs(v);
    }
  };

  dfs(1);
  cout << (maxD * 2);
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