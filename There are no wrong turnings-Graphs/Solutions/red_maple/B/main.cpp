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
  int k, n, m; cin >> k >> n >> m;

  vector<vector<vector<char>>> par(k, vector<vector<char>>(n, vector<char>(m)));

  for (auto i = 0; i < k; ++i) {
    for (auto j = 0; j < n;++j) {
      for (auto p = 0; p < m; ++p) {
        cin >> par[i][j][p];
      }
    }
  }

  int a, b; cin >> a >> b;
  a--; b--;

  int time = 0;

  auto isValid = [&](int uk, int ux, int uy) -> bool {
    if (uk < 0 or uk >= k) return false;
    if (ux < 0 or ux >= n) return false;
    if (uy < 0 or uy >= m) return false;
    if (par[uk][ux][uy] !=  '.') return false;
    return true;
  };

  queue<vector<int>> q;
  vector<vector<int>> delta = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

  function<void(int, int, int)> dfs = [&](int k, int x, int y) {
    if (par[k][x][y] != '.') return;
    
    par[k][x][y] = '+';
    time ++;

    if (isValid(k + 1, x, y)) {
      dfs(k + 1, x, y);
    } 

    for (auto d : delta) {
      if (!isValid(k, x + d[0], y + d[1])) continue;
      dfs(k, x + d[0], y + d[1]);
    }

    if (isValid(k - 1, x, y)) {
      dfs(k - 1, x, y);
    }
  };

  dfs(0, a, b);
  cout << time;
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