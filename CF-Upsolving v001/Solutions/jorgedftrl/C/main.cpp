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

    int n, z; cin >> n >> z;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int &i = ans, j = n/2; i < n/2 and j < n; ++j) {
        if ( a[i] + z <= a[j]) ++i;
    }
    cout << ans;

    return 0;
}
