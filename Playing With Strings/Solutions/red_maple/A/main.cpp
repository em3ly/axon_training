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


class KMP{
private:
  string pattern;
  vector<int> f;

public:
  KMP(string pattern) {
    this->pattern = pattern;
    f = vector<int>(pattern.size(), -1);

    for (int k = -1, i = 1; i < (int)pattern.size(); ++i) {
      while (k >= 0 and pattern[k + 1] != pattern[i]) {
        k = f[k];
      }

      if (pattern[k + 1] == pattern[i]) {
        k++;
      }

      f[i] = k;
    }
  }

  void printF() {
    for (auto it : f) {
      cout << it << " ";
    }
    cout << endl;
  }

  vector<int> getAllMatch(const string & text) {
    vector<int> ret;

    for (int k = -1, i = 0; i < (int)text.size(); ++i) {
      while (k >= 0 and text[i] != pattern[k + 1]) {
        k = f[k];
      }

      if (text[i] == pattern[k + 1]) {
        k++;
      }

      if (k == (int)pattern.size() - 1) {
        ret.push_back(i - k);
      }
    }

    return ret;
  }
};

void solve(){
  int t; cin >> t;
  while (t--) {
    string text, pattern;
    cin >> text >> pattern;

    KMP kmp(pattern);
    
    auto out = kmp.getAllMatch(text);

    if (out.size() == 0) {
      cout << "Not Found" <<endl;
    } else {
      cout << out.size() <<endl;
      for (auto it : out) {
        cout << (it + 1) << " ";
      }
      cout <<endl;
    }
    if (t != 0){
      cout << endl;  
    }
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


