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
    int kase = 1;
    while (n--) {
      string t; cin >> t;
      int k; cin >> k;
      vector<string> dic;
      for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        dic.push_back(s);
        reverse(s.begin(), s.end());
        dic.push_back(s);
      }
      vector<int> dp(t.size()+1, -1);
      dp[0] = 0;
      queue<int> q;
      q.push(0);

      while (!q.empty()) {
        auto i = q.front(); q.pop();

        for (auto s : dic) {
          string ts = t.substr(i, s.size());
          if (ts == s) {
            if (dp[i+s.size()] == -1) {
              dp[i+s.size()] = dp[i] + 1;
              q.push(i+s.size());
            }
          }
        }
      }

      cout << "Set " << kase++ << ": ";
      if (dp[t.size()] == -1) {
        cout << "Not possible";
      } else {
        cout << dp[t.size()];
      }
      cout << "." << endl;
    }

    return 0;
}
