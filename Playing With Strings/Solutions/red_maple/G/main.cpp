/*
    Date 05/28/2019
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

vector<int> getF(string & s) {
  vector<int> f(s.size(), -1);
  
  int n = s.size();
  for (int k = -1, i = 1;  i < n;  ++i) {
    while (k >= 0 and s[i] != s[k + 1]) {
      k = f[k];
    }

    if (s[i] == s[k + 1]) {
      k++;
    }

    f[i] = k;
  }
  return f;
}

bool exist(vector<int> & f, int ind, string & s) {
  int n = f.size();

  for (int i = 0, j = n - 1 - ind; j < (int)s.size(); i++, j++) {
    if (s[i] != s[j]) return false;
  }

  for (int i = 1; i < (int)s.size() - 1; ++i) {
    if (f[i] == ind) return true;
  }
  return false;
}

void solveG() {
  string s; cin >> s;

  vector<int> f = getF(s);

  if (f[f.size() - 1] == -1) {
    cout << "Just a legend";
    return;
  }

  int cnt = 0;
  for (int i = f[f.size() - 1], ind = f.size() - 1 ; i >= 0; ind = i, i = f[i]) {
    
    if (cnt >=2) {
      cout << s.substr(0, ind + 1);
      return;
    }

    if (exist(f, i, s)) {
      cout  << s.substr(0, i + 1);
      return;
    }

    cnt++;
  }

  cout << "Just a legend";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solveG();
  return 0;
}


