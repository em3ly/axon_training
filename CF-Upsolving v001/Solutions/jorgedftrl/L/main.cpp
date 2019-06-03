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
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  int mn = *min_element(a.begin(), a.end());
  int cnt = count_if(a.begin(), a.end(), [&](int v) -> bool { return v == mn; });
  if (cnt <= n/2) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
  return 0;
}
