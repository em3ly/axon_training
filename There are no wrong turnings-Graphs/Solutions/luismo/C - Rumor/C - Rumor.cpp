/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: C - Rumor
	Online Judge: codeforces.com
	Idea: Get the maximmum bribe needed for each connectec component
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
const int lim = 1e5 + 2;


int n, m;
ll bribe[lim];

int taken[lim];
int level[lim];

vector<int> adj[lim];

ll BFS(int idx)
{
    ll ret = bribe[idx];

    queue<int> q;
    level[idx] = 0;
    q.push(idx);
    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();
        taken[curr] = 1;

        ret = min(ret, bribe[curr]);

        // for each adjacent
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];

            if(!taken[nxt])
            {
                level[nxt] = level[curr] + 1;
                q.push(nxt);
            }
        }
    }
    return ret;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> bribe[i+1];
    }

    // reading adjacency
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll answ = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!taken[i])
        {
            ll k = BFS(i);
            answ += k;
        }
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