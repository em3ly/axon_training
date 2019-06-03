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
    string s; cin >> s;

    int mn = 0, cur = 0;

    for (char c : s) {
        if (- == c) {
            --cur;
        } else {
            ++cur;
        }
        mn = min(mn, cur);
    }
    cout << cur - mn;

    return 0;
}
