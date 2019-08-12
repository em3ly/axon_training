/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: Matching
	Online Judge: https://atcoder.jp/contests/dp/tasks/dp_o
	Idea: DP + BitMask
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
const int lim = (1ll<<22) + 2;

int N;
int mt[100][100];

ll dp[23][lim];
bool mark[23][lim];

ll DynammicProgramming(int idx, ll mask)
{
	if(idx == 0)
		return 1;
	
	if(mark[idx][mask])
		return dp[idx][mask];
	
	for(int i = 1; i <= N; i++)
	{
		// if can be matched and not active
		if(mt[idx][i] && ((1<<i) & mask) == 0)
		{
			ll k = DynammicProgramming(idx - 1, mask | (1<<i));
			dp[idx][mask] = (dp[idx][mask] + k) % mod;
		}
	}
	// mark the state as visited
	mark[idx][mask] = true;
	return dp[idx][mask];
}


void solve()
{
	cin >> N;
	for(int i = 1; i <= N; i++)	
	{
		for(int j = 1; j <= N; j++)
			cin >> mt[i][j];
	}

	ll answ = DynammicProgramming(N, 0);
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