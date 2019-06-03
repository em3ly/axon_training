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
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        if (i > 0) {
            ans = min(ans, ai/i);
        }
        if (i < n-1) {
            ans = min(ans, ai/(n-i-1));
        }
    }
    cout << ans;

    return 0;
}

