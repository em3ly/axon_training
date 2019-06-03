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

bool equals(string & p, string & s, int ind) {
  int i = ind;
  int j = 0;
  for(; i < (int)s.size() and j < (int)p.size(); i++, j++) {
    if(s[i] != p[j]) return false;
  } 
  if(j < (int) p.size()) return false;
  return true;
}

void solveH(){
  int t; cin >> t;

  for(auto i = 1; i <= t; ++i){
    string s; cin >> s;
    int n; cin >> n;
    set<string> strSet;
    for(auto  i = 0; i < n; ++i) {
      string st; cin >> st;
      strSet.insert(st);
      reverse(st.begin(), st.end());
      strSet.insert(st);
    }

    vector<string> str(strSet.begin(), strSet.end());

   queue<int> nextStr, strCnt;
   nextStr.push(0);
   strCnt.push(0);

   set<int> seenInd;

   bool found = false;
   int minCnt = INT_MAX;

   while(!nextStr.empty() and !found) {
      int ind = nextStr.front(); nextStr.pop();
      int cnt = strCnt.front(); strCnt.pop();

      for(string p: str) {
        if(equals(p, s, ind)) {
          if((ind + (int)p.size()) == (int)s.size()) {
            found = true;
            minCnt = cnt + 1;
            break;
          }

          if(!seenInd.count(ind + p.size())) {
              nextStr.push(ind + p.size());
              strCnt.push(cnt + 1);
              seenInd.insert(ind + p.size());
          }
            
        }  
      }
   }

 
    cout << "Set " << i << ": ";
    if(!found) {
      cout << "Not possible." <<endl;
    } else {
      cout << minCnt << "." <<endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.precision(precision);
  cout.setf(ios_base::fixed);
  solveH();
  return 0;
}


