/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: A - Frog 1
	Online Judge:
	Idea: Easy DP
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
ll hi[lim];

ll dp[lim];
int mark[lim];

ll DynamicProgramming(int idx)
{
    if(idx <= 0)
        return 0;

    if(mark[idx])
        return dp[idx];

    mark[idx] = true;

    DynamicProgramming(idx - 1);
    DynamicProgramming(idx - 2);

    ll k1 = dp[idx-1] + abs(hi[idx] - hi[idx-1]);
    ll k2 = (idx > 1) ? dp[idx-2] + abs(hi[idx] - hi[idx-2]) : inf;

    dp[idx] = min(k1, k2);
    return dp[idx];
}


void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> hi[i];   

    ll answ = DynamicProgramming(N - 1);
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