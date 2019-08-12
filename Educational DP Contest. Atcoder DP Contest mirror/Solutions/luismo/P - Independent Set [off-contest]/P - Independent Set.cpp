/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem:
	Online Judge:
	Idea:
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
const int lim = 2e5 + 17 ;

int N, xi, yi;

vector<int> adj[lim];

ll dp[lim][2];
bool mark[lim][2];

// 0-white, 1-black

ll DFS(int idx, int father, int color)
{
	if(mark[idx][color])
		return dp[idx][color];

	ll curr = 1;
	
	for(int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if(nxt != father)
		{
			ll aux = DFS(nxt, idx, 0);

			

			if(!color)
			{
				ll aux2 = DFS(nxt, idx, 1);

				aux = (aux + aux2) % mod;				
			}

			curr = (curr * aux) % mod;
		}
	}
	mark[idx][color] = true;
	dp[idx][color] = curr;

	// cout << idx << " " << color << " " << curr << endl;

	return dp[idx][color];
}


void solve()
{
	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		cin >> xi >> yi;
		adj[xi].push_back(yi);
		adj[yi].push_back(xi);
	}

	ll a1 = DFS(1, -1, 0);

	ll a2 = DFS(1, -1, 1);

	// cout << a1 << " "<< a2 << endl;

	ll answ = (a1 + a2) % mod;
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
