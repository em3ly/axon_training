/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: G - Longest Path
	Online Judge: 
	Idea: DP on Graph
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

int N, M;
vector<int> adj[lim];

int dp[lim];
bool mark[lim];

int DFS(int idx)
{
    if(mark[idx])
        return dp[idx];
    // for each adjacent
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];
        int aux = DFS(nxt);
        dp[idx] = max(dp[idx], 1 + aux);
    }
    mark[idx] = true;
    return dp[idx];
}

void solve()
{
    cin >> N >> M;
    // reading edges
    for (int i = 0; i < M; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        adj[xi].push_back(yi);
    }
    
    int answ = 0;

    for(int i = 1; i <= N; i++)
    {
        int aux = DFS(i);
        answ = max(answ, aux);
    }

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