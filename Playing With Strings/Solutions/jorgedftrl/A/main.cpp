#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <tuple>
#include <functional>

using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    string a, b; cin >> a >> b;
    vector<int> f(b.size(), -1);
    for (int i = 1, k = -1; i < (int)b.size(); ++i) {
      while (k >= 0 and b[i] != b[k+1]) k = f[k];
      if (b[i] == b[k+1]) ++k;
      f[i] = k;
    }

    vector<int> ans;
    for (int i = 0, k = -1; i < (int)a.size(); ++i) {
      while (k >= 0 and a[i] != b[k+1]) k = f[k];
      if (a[i] == b[k+1]) ++k;
      if (k + 1 == b.size()) ans.push_back(i + 2 - b.size());
    }
    if (ans.size()) {
      cout << ans.size() << endl;
      for (auto i : ans) cout << i << " ";
      cout << endl;
    } else {
      cout << "Not Found" << endl;
    }
    if (n) cout << endl;
  }

  return 0;
}
