/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: C - Vacation
	Online Judge:
	Idea: Easy DP.
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
const int lim = 2e5 + 2;

int N;

ll ai, bi, ci;
ll dp[lim][3];

void solve()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        cin >> ai >> bi >> ci;
        dp[i][0] = ai + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = bi + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = ci + max(dp[i-1][1], dp[i-1][0]);
    }

    ll answ = max(dp[N][0], max(dp[N][1], dp[N][2]));
    cout << answ;
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