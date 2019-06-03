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
    int pprev, prev; cin >> pprev >> prev;
    int ans = 1 == prev ? pprev + 1 : prev + 1;
    string out = "Finite";
    if (5 == pprev + prev) {
        out =  "Infinite";
    }

    for (int i = 3; i <= n; ++i) {
        int cur; cin >> cur;
        if (5 == cur + prev) {
            out = "Infinite";
        }
        if (1 == cur) {
            ans += prev + 1;
        } else {
            ans += cur + 1;
        }
        if (3 == pprev and 2 == cur) {
            --ans;
        }
        pprev = prev;
        prev = cur;
    }


    cout << out << endl;
    if ("Finite" == out) {
        cout << ans;
    }

    return 0;
}
