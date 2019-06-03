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

    int n, k; cin >> n >> k;

    map<int, set<int>> mp;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        mp[x].insert(i+1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (mp[i].size() == 0)++ans;

        mp[i].insert(k+1);
        if (i-1) {
            mp[i-1].insert(0);
            if (*mp[i-1].rbegin() <= *mp[i].begin()) ++ans;
            mp[i-1].erase(0);
        }
        if (i+1 <= n) {
            mp[i+1].insert(0);
            if (*mp[i+1].rbegin() <= *mp[i].begin()) ++ans;
            mp[i+1].erase(0);
        }
        mp[i].erase(k+1);
    }
    cout << ans;
    return 0;
}
