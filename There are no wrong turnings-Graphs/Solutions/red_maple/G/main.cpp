#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;

const int precision = 3;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;
const ll inf = 1e18;

void solve() {

  ll n, m, s; cin >> n >> m >> s;

  ll mRows = ((n - 1) / s) * s + 1;
  ll mCols = ((m - 1) / s) * s + 1;

  ll maxN = ((n - 1) / s + 1) * ((m - 1) / s + 1);

  ll ret = (n - mRows + 1) * (m - mCols + 1) * maxN;
  cout <<  ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solve();
  return 0;
}