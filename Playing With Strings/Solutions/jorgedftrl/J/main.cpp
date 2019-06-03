#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <tuple>
#include <functional>

using namespace std;

#define endl n

using ull = unsigned long int;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int precision = 13;
  cout.precision(precision);
  cout.setf(ios_base::fixed);

  int T; cin >> T;

  while (T--) {
    string s; cin >> s;
    int n; cin >> n;

    vector<int> f(s.size(), -1);
    for (int i = 1, k = -1; i < (int)s.size(); ++i) {
      while (k >= 0 and s[k+1] != s[i]) k = f[k];
      if (s[k+1] == s[i]) ++k;
      f[i] = k;
    }
    int len = s.size();
    cout << 1ll * len + 1ll * (len - f[len-1] - 1) * (n-1) << endl;
  }

  return 0;
}
