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
    auto a = vector<vector<int>>(n, vector<int>(m));
    auto b = a;
    for (auto &v : a) for (auto &it : v) cin >> it;
    for (auto &v : b) for (auto &it : v) cin >> it;

    string ans = "Possible";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
            if (i > 0) {
                if (a[i][j] <= a[i-1][j] or b[i][j] <= b[i-1][j]) {
                    ans = "Impossible";
                }
            }
            if (j > 0) {
                if (a[i][j] <= a[i][j-1] or b[i][j] <= b[i][j-1]) {
                    ans = "Impossible";
                }
            }
        }
    }

    cout << ans;

    return 0;
}
