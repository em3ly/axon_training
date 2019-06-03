#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <tuple>
#include <functional>
#include <map>

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

  string s; cin >> s;
  vector<int> f(s.size(), -1);
  for (int k = -1, i = 1; i < (int)s.size(); ++i) {
    while (k >= 0 and s[i] != s[k+1]) k = f[k];
    if (s[i] == s[k+1]) ++k;
    f[i] = k;
  }

  set<int> st;
  for (int k = f[s.size() - 1]; k >= 0; k = f[k]) {
    st.insert(k);
  }

  int mx = -1;
  for (int i = 1; i < (int)s.size() - 1; ++i) {
    if (st.count(f[i]) and f[i] > mx) mx = f[i];
  }
  if (mx == -1) {
    cout << "Just a legend" << endl;
  } else {
    cout << s.substr(0, mx+1) << endl;
  }

  return 0;
}
