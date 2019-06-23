/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: A - Party
	Online Judge: codeforces.com
	Idea: BFS.
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
const int lim = 2e3 + 2;


int n;
int pi[lim];

int taken[lim];
int level[lim];

vector<int> adj[lim];


int BFS(int idx)
{
    int ret = 0;

    queue<int> q;
    level[idx] = 1;
    q.push(idx);
    while(q.size() > 0)
    {
        int curr = q.front(); q.pop();
        taken[curr] = 1;

        ret = max(ret, level[curr]);

        // for each adjacent
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int nxt = adj[curr][i];

            level[nxt] = level[curr] + 1;
            q.push(nxt);
        }
    }
    return ret;
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        pi[i+1] = p;
        adj[p].push_back(i+1);
    }

    int answ = 0;

    for(int i = 1; i <= n; i++)
    {
        if(pi[i] == -1)
        {
            int k = BFS(i);
            answ = max(answ, k);
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