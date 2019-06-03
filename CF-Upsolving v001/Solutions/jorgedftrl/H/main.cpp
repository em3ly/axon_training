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

    int n, h, m; cin >> n >> h >> m;
    vector<int> vals(n, h);

    for (int i = 1; i <= m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int k = l-1; k <= r-1; ++k) vals[k] = min(vals[k], x);
    }

    cout << accumulate(vals.begin(), vals.end(), 0, [&](int x, int y) -> int {return x + y*y; });
    
    return 0;
}
