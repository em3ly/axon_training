#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl n

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(2 * n + 1);

    auto add = [&](int a, int b) {
      int d = (b - a + n) % n;
      v[a].push_back(d);
      v[a+n].push_back(d);
    };

    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b;
      -- a; -- b;
      add(a, b);
      add(b, a);
    }

    vector<int> f(n*2 + 1, -1);
    sort(v[0].begin(), v[0].end());
    for (int i = 1, j = -1; i < 2*n-1; ++i) {
      sort(v[i].begin(), v[i].end());
      while (j >= 0 and v[i] != v[j+1]) {
        j = f[j];
      }
      if (v[i] == v[j+1]) {
        ++j;
      }
      if (j == n-1) {
        cout << "Yes";
        return 0;
      }
      f[i] = j;
    }
    cout << "No";

    return 0;
}
