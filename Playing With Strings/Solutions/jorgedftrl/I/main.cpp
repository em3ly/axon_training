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

class node {
public:
  vector<node*> next;
  int id;
  int rep;
  node() {
    next = vector<node*>(27, nullptr);
    id = -1;
    rep = -1;
  }
};

class trie {
public:
  node* root = nullptr;
  trie() {
    root = new node();
  }

  ~trie(){ clean(root);  }

  void clean(node* cur) {
    for (auto nx : cur->next) {
      if (nx) {
        clean(nx);
      }
    }
    delete cur;
  }

  void add(const string& s, int id, int rep) {
    node* cur = root;
    for (int i = 0; i < (int)s.size(); ++i) {
      int ind = s[i] - a;
      if (!cur->next[ind]) {
        cur->next[ind] = new node();
      }
      cur = cur->next[ind];
      if (cur->rep < rep) {
        cur->rep = rep;
        cur->id = id;
      }
    }
  }

  int get(const string& pref) {
    node* cur = root;
    for (int i = 0; i < (int)pref.size(); ++i) {
      int ind = pref[i] - a;
      if (!cur->next[ind]) return -1;
      cur = cur->next[ind];
    }
    return cur->id;
  }
};


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int precision = 13;
  cout.precision(precision);
  cout.setf(ios_base::fixed);

  map<string, int> mp;
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s; ++mp[s];
  }

  trie t;
  vector<string> v;

  for (auto it : mp) {
    v.push_back(it.first);
    t.add(it.first, v.size() - 1, it.second);
  }

  int q; cin >> q;
  while (q--) {
    string pref; cin >> pref;
    int ans = t.get(pref);
    if (ans != -1) {
      cout << v[ans] << " " << mp[v[ans]] << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
