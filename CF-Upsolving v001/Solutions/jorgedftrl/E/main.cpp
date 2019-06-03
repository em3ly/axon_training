#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <tuple>
#include <functional>

using namespace std;


int p2(int n) {
  int p = 1;
  while ((1<<p) <= n)p++;
  --p;
  return p;
}


class St {
public:
  vector<set<int>> st = vector<set<int>>(1e6);
  const int P = 1<<20;
  int n;
  St(vector<int>& a) {
    n = a.size();
    for (int i = 0; i < (int)a.size(); ++i) add(0, 0, n, i, a[i]);
  }
  void add(int x, int l, int r, int pos, int val) {
    if (pos > r or pos < l) return;
    if (l == r) {
      st[x].insert(val);
      return;
    }
    int mid = (l + r)/2;
    if (pos <= mid) {
      add(x*2 + 1, l, mid, pos, val);
    } else {
      add(x*2 + 2, mid+1, r, pos, val);
    }
    st[x].insert(val);
  }
  bool find(int from, int to, int val) {
    return find(0, 0, n, from, to, val);
  }
  bool find(int x, int l, int r, int from, int to, int val) {
    if (l > to or r < from) return false;
    if (l >= from and r <= to) return st[x].find(val) != st[x].end();
    int mid = (l+r)/2;
    return find(x*2+1, l, mid, from, to, val) or find(x*2+2, mid+1, r, from, to, val);
  }
};

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  St sst(a);

  vector<vector<int>> st(20, vector<int>(n, 0));
  auto idx = st;
  iota(idx[0].begin(), idx[0].end(), 0);
  st[0] = a;
  for (int p = 1, l = 1; p < n; p <<= 1, ++l) {
    for (int i = 0; i < n; ++i) {
      st[l][i] = st[l-1][i];
      idx[l][i] = idx[l-1][i];
      if (i+p < n and st[l][i] < st[l-1][i+p]) {
        st[l][i] = st[l-1][i+p];
        idx[l][i] = idx[l-1][i+p];
      }
    }
  }

  auto rmq = [&](int from, int to) -> tuple<int, int>  {
               int d = to - from;
               int p = p2(d);
               if (st[p][from] > st[p][to-(1<<p)]) {
                 return tuple<int, int>{idx[p][from], st[p][from]};
               } else {
                 return tuple<int, int>{idx[p][to-(1<<p)], st[p][to-(1<<p)]};
               }
  };

  function<long long(int, int)> solve =
    [&] (int from, int to) -> long long {
      if (from + 1 >= to) {
        return 0;
      }
      int mx = -1;
      int ind = -1;
      auto t = rmq(from, to);
      mx = get<1>(t);
      ind = get<0>(t);
      long long ans = 0;
      if (ind-from < to - ind) {
        ans += solve(ind+1, to);
        for (int i = from; i < ind; ++i) {
          auto targ = mx - a[i];
          if (sst.find(ind+1, to, targ)) ++ans;
        }
        ans += solve(from, ind);
      } else {
        ans += solve(from, ind);
        for (int i = ind+1; i < to; ++i) {
          auto targ = mx - a[i];
          if (sst.find(from, ind, targ)) ++ans;
        }
        ans += solve(ind+1, to);
      }
      return ans;
    };

  cout << solve(0, n) << endl;

  return 0;
}
