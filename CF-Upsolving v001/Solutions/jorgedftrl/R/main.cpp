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

    int n; cin >> n;
    vector<pair<int, int>> poles;
    for (int i = 0; i < n; ++i) {
      int x, y; cin >> x >> y;
      poles.emplace_back(x, y);
    }

    map<pair<int, int>, set<int>> lines;
    int cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        int x1 = poles[i].first;
        int y1 = poles[i].second;
        int x2 = poles[j].first;
        int y2 = poles[j].second;

        int A = y1 - y2;
        int B = x2 - x1;
        int C = x2*y1 - x1*y2;
        int g = __gcd(C, __gcd(A, B));
        A /= g;
        B /= g;
        C /= g;

        if (lines[{A, B}].find(C) == lines[{A, B}].end()) {
          ++cnt;
          lines[{A, B}].insert(C);
          ans += cnt - lines[{A, B}].size();
        }
      }
    }
    cout << ans;

    return 0;
}
