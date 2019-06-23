/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: E - The Tag Game
	Online Judge: codeforces.com
	Idea: Nice problem, find the greatest distance from Alice to each node and do the same for Bob.
	Then take the node in which bob arrives first than alice with greatest distance
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
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;


int n, x;

vector<int> adj[lim];

int lvAlice[lim];
int lvBob[lim];

void DFS(int idx, bool alice)
{
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        if(alice)
        {
            if(lvAlice[nxt] == 0)
            {
                lvAlice[nxt] = lvAlice[idx] + 1;
                DFS(nxt, alice);
            }
        }
        else
        {
            if(lvBob[nxt] == 0)
            {
                lvBob[nxt] = lvBob[idx]  +1;
                DFS(nxt, alice);
            }
        }
    }
}

void solve()
{
    cin >> n >> x;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lvAlice[1] = 1;
    DFS(1, true);
    lvBob[x] = 1;
    DFS(x, false);

    int answ = lvAlice[x];

    for(int i = 1; i <= n; i++)
    {
        if(lvBob[i] < lvAlice[i] && lvAlice[i] > answ)
            answ = lvAlice[i];
    }

    cout << 2 * ( answ - 1);
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