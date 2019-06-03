#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define endl n

using ull = unsigned long int;
using ll = long long;

template <class Key, class Val>
using hmap = gp_hash_table<Key, Val>;


class dsu {
        vector<int> st, w;

    public:
        dsu(int sz) {
            st.resize(sz+1);
            w.assign(sz+1, 1);
            iota(st.begin(), st.end(), 0);
        }

        int size(int v) {return w[group(v)];}

        int group(int v) {
            if (v == st[v]) return v;
            return st[v] = group(st[v]);
        }

        int join(int u, int v) {
            u = group(u);
            v = group(v);
            if (v != u) {
                if (w[u] < w[v]) swap(u, v);
                w[u] += w[v];
                st[v] = u;
            }
            return u;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int precision = 13;
    cout.precision(precision);
    cout.setf(ios_base::fixed);

    int n; cin >> n;
    vector<vector<int>> adj = vector<vector<int>>(n+1);
    auto col = adj;

    dsu d1(n+1), d0(n+1);

    for (int i = 1; i < n; ++i) {
        int u, v, c; cin >> u >> v >> c;
        if (c) {
            d1.join(u, v);
        } else {
            d0.join(u, v);
        }

        adj[u].push_back(v);
        col[u].push_back(c);


        adj[v].push_back(u);
        col[v].push_back(c);
    }

    set<pair<int, int>> st;
    set<int> s0, s1;
    for (int i = 1; i <= n; ++i) {
        int u = i;
        s0.insert(d0.group(u));
        s1.insert(d1.group(u));
        for (int j = 0; j < (int)adj[u].size(); ++j) {
            int v = adj[u][j];
            if (d0.size(u) > 1 and col[u][j]) {
                st.insert({d0.group(u), d1.group(v)});
            }
        }
    }

    ll ans = 0;
    for (auto u : s0) ans += 1ll * d0.size(u) * (d0.size(u) - 1);
    for (auto u : s1) ans += 1ll *d1.size(u) * (d1.size(u) - 1);
    for (auto p : st) {
        ans += 1ll * (d0.size(p.first) - 1) * (d1.size(p.second) - 1);
    }
    cout << ans;

    return 0;
}
