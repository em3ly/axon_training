/*
    Date 05/27/2019
    Brenda E Ramirez.
*/



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

vector<int> getF(string & pattern) {
  auto  f = vector<int>(pattern.size(), -1);

  for (int k = -1, i = 1; i < (int)pattern.size(); ++i) {
    while (k >= 0 and pattern[k + 1] != pattern[i]) {
      k = f[k];
    }

    if (pattern[k + 1] == pattern[i]) {
      k++;
    }

    f[i] = k;
  }

  return f;
}

void solve(){
  int t; cin >> t;
  while(t--) {
    string pattern; cin >> pattern;

    auto f = getF(pattern);

    int cnt; cin >> cnt;

    cnt--;
    int rest = pattern.size() - (f[f.size() - 1] + 1);

    ll len = pattern.size() + (rest * cnt);
    cout << len << endl;
  }
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


