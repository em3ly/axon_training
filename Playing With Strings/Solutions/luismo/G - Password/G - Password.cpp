/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: G - Password
	Online Judge:
	Idea: Use the Prefix Function
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
const int lim = 1e6 + 2;

map<int, vector<int> > m;

string str;
int pi[lim];

void prefixFunction()
{
    int matched = 0;
    for(int i = 1; i < str.size(); i++)
    {
        while(matched > 0 && str[i] != str[matched])
            matched = pi[matched - 1];
        if(str[i] == str[matched])
            matched++;

        pi[i] = matched;

        m[matched].push_back(i);
    }
}

void solve()
{
    cin >> str;
    prefixFunction();

    int k = pi[str.size() - 1];

    if(m[k].size() < 2)
        k = pi[k - 1];

    if(k == 0)
        cout << "Just a legend";
    else
        for(int i = 0; i < k; i++)
            cout << str[i];
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
