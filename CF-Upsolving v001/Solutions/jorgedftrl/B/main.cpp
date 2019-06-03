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

    int T; cin >> T;
    while (T--) {
        map<char, int> cnt;
        string s; cin >> s;
        for (char c : s) {
            ++cnt[c];
        }
        if (cnt.size() == 1) {
            cout << s << endl;
        } else  if (2 == cnt.size()) {
            if (cnt.begin()->first + 1 == cnt.rbegin()->first) {
                cout << "No answer" << endl;
            } else {
                for (auto it : cnt) {
                    for (int i = 0; i < it.second; ++i)cout << it.first;
                }
                cout << endl;
            }
        } else if (3 == cnt.size()) {
            if (cnt.begin()->first + 2 == cnt.rbegin()->first) {
                cout << "No answer" << endl;
            } else {
                if (cnt.begin()-> first + 1 == next(cnt.begin())->first) {
                    for (int i = 0; i < cnt.begin()->second; ++i) {
                        cout << cnt.begin()->first;
                    }
                    for (int i = 0; i < cnt.rbegin()->second; ++i) {
                        cout << cnt.rbegin()->first;
                    }
                    for (int i = 0; i < next(cnt.begin())->second; ++i) {
                        cout << next(cnt.begin())->first;
                    }
                    cout << endl;
                } else {
                    for (int i = 0; i < next(cnt.begin())->second; ++i) {
                        cout << next(cnt.begin())->first;
                    }
                    for (int i = 0; i < cnt.begin()->second; ++i) {
                        cout << cnt.begin()->first;
                    }
                    for (int i = 0; i < cnt.rbegin()->second; ++i) {
                        cout << cnt.rbegin()->first;
                    }
                    cout << endl;
                }
            }
        } else {
            vector<char> v;
            for (auto it : cnt) v.push_back(it.first);
            for (int i = 0, l = -1; i < (int)cnt.size(); ++i) {
                int offset = 0;
                if (i%2 == 0) {
                    ++l;
                    offset = v.size()/2;
                }
                for (int k = 0; k < cnt[v[l + offset]]; ++k) {
                    cout << v[l + offset];
                }
            }
            cout << endl;
        }
    }

    return 0;
}
