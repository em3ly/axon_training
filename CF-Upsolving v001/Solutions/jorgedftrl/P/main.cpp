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
    map<int, set<int>> mp;
    map<int, int> cnt;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        ++cnt[u];
        mp[cnt[u]].insert(u);
        auto prev = cnt[u] - 1;
        if (prev) {
            mp[prev].erase(u);
            if (mp[prev].size() == 0) mp.erase(prev);
        }
        if (mp.size() == 1) {
            if (mp.begin()->second.size() == 1 or 1 == mp.begin()->first) {
                ans = max(ans, i+1);
            }
        } if (mp.size() == 2) {
            if (mp.begin()->first == 1 and mp.begin()->second.size() == 1) {
                ans = max(ans, i+1);
            } else if (mp.rbegin()->first == mp.begin()->first + 1 and mp.rbegin()->second.size() == 1) {
                ans = max(ans, i+1);
            }
        }
    }
    cout << ans;

    return 0;
}
