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

void solve(){
  int n; cin >> n;

  vector<vector<int>> adj(n + 1);

  vector<int> boss;
  for(auto i = 1; i <= n; ++i) {
    int m; cin >> m;
    if(m == -1) {
      boss.push_back(i);
      continue;
    }
    adj[m].push_back(i);
  }

  unordered_map<int, vector<int>> height;

  vector<bool> seen(n + 1,  0);

  auto bfs = [&](int root) {
    seen[root] = true;
    queue<int> q, h;
    q.push(root);
    h.push(0);

    while(!q.empty()) {
      auto u = q.front(); q.pop();
      auto hu = h.front(); h.pop(); 

      height[hu].push_back(u);
      for(auto v : adj[u]) {
        if(seen[v]) continue;
        seen[v] = true;
        q.push(v);
        h.push(hu + 1);
      }
    }
  };

  for(auto it : boss) {
    bfs(it);
  }
  cout << height.size();
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