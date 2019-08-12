/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: F - LCS
	Online Judge: 
	Idea: Classic LCS with string reconstruction
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 3e3 + 2;

string s, t;

int dp[lim][lim];
bool mark[lim][lim];

pii stat[lim][lim];

int DynamicProgramming(int ls, int rs)
{
    if(ls == 0 || rs == 0)
        return 0;

    if(mark[ls][rs])
        return dp[ls][rs];
    
    mark[ls][rs] = true;

    int idxs = ls - 1;
    int idxr = rs - 1;

    int s1 = DynamicProgramming(ls, rs - 1);
    int s2 = DynamicProgramming(ls - 1, rs);

    int s3 = 0;
    if(s[ls-1] == t[rs-1])
        s3 = 1 + DynamicProgramming(ls - 1, rs - 1);

    int mx = max(max(s1, s2), s3);

    if(s1 >= s2 && s1 >= s3)
        stat[ls][rs] = mkp(ls, rs - 1);
    if(s2 >= s1 && s2 >= s3)
        stat[ls][rs] = mkp(ls - 1, rs);
    if(s3 >= s1 && s3 >= s2)
        stat[ls][rs] = mkp(ls - 1, rs - 1);
    

    dp[ls][rs] = mx;
    return mx;
}

void solve()
{
    cin >> s >> t;

    int cnt = DynamicProgramming(s.size(), t.size());

    string answ = "";

    int l = s.size();
    int r = t.size();
    
    while(l > 0 && r > 0)
    {
        
        if(s[l-1] == t[r-1])
        {
            
            answ = s[l-1] + answ;
        }
        int xl = stat[l][r].first;
        int xr = stat[l][r].second;
        l = xl;
        r = xr;
    }
    // print answer
    cout << answ << endl;    
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}