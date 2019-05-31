/*
    Date 05/29/2019
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

class TrieNode{
public:
  vector<shared_ptr<TrieNode>> trans;
  bool isLeaf;

  int strId;

  TrieNode(bool isLeaf, int id) {
    trans = vector<shared_ptr<TrieNode>>(26, nullptr);
    this->isLeaf = isLeaf;
    this->strId = id;
  }
};

class Trie {
private:
  shared_ptr<TrieNode> root;
  map<string, pair<int, int>> strs;
  unordered_map<int, string> strById;

public:

  Trie(map<string, pair<int, int>> strs, 
   unordered_map<int, string> strById) {

    root = make_shared<TrieNode>(false, 0);
    this->strs = strs;
    this->strById = strById;
  }

  void insert(const string & s) {
    
    int wCount = strs[s].first;
    int id = strs[s].second;

    shared_ptr<TrieNode> cur = root;

    for(auto c : s) {
      if(!cur->trans[c - 'a']) {
        cur->trans[c - 'a'] = make_shared<TrieNode>(false, id);
      } else {
        auto & curId = cur->trans[c - 'a']->strId;
        auto curCnt = strs[strById[curId]].first;

        if(curCnt < wCount) {
          curId = id;

        }
      }

      cur = cur->trans[c - 'a'];
    }

    cur->isLeaf = true;
  } 


  string query(string & prefix) {
    shared_ptr<TrieNode> cur = root;

    for(auto c : prefix) {
      if(!cur->trans[c - 'a']) return "-1";
      cur = cur->trans[c - 'a'];
    }

    string ret = strById[cur->strId];
    int cnt = strs[ret].first;

    return ret + " " + to_string(cnt);
  }
};

void solveI() {
  int n; cin >> n;
  map<string, pair<int, int>> strs;
  unordered_map<int, string> strById;

  int id = 0;


  while(n--) {
    string s; cin >> s;
    if(!strs.count(s)) {
      strs[s].second = id;
      strById[id] = s;
      id++;
    }
    strs[s].first++;
  }

  Trie trie(strs, strById);

  for(auto it : strs) {
    trie.insert(it.first);
  }

  //trie.print();

  int q; cin >> q;
  unordered_map<string, string> queries;

  while(q--) {
    string prefix; cin >> prefix;
    if(!queries.count(prefix)) {
      queries[prefix] = trie.query(prefix);
    }
    cout << queries[prefix] << endl <<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solveI();
  return 0;
}


