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
    vector<ll> b(n), g(m);
    for (auto &i : b) cin >> i;
    for (auto &i : g) cin >> i;

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    if (*b.rbegin() > *g.begin()) {
        cout << -1;
        return 0;
    }

    ll ans = m * accumulate(b.begin(), b.end(), 0ll);
    for (int i = n-1, j = m-1; i >= 0  and j >= 0; --j) {
        if (g[j] < b[i]) --i;
        ans -= b[i];
        ans += g[j];
    }
    if (g[0] > b[n-1]) {
        ans += b[n-1];
        ans -= b[n-2];
    }
    cout << ans;

    return 0;
}
