/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: I - Road Map
	Online Judge: codeforces.com
	Idea: Simple DFS an build the fatherhood path
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


int n, r1, r2;
int pi[lim];

vector<int> adj[lim];
int level[lim];
int answPi[lim];

void DFS(int idx)
{
    for(int i = 0; i < adj[idx].size(); i++)
    {
        int nxt = adj[idx][i];

        if(answPi[nxt] == 0)
        {
            answPi[nxt] = idx;
            DFS(nxt);
        }
    }
}

void solve()
{
    cin >> n >> r1 >> r2;

    for(int i = 1; i <= n; i++)
    {
        if(i != r1)
        {
            int x; cin >> x;
            pi[i] = x;
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }


    pi[r2] = -1;
    DFS(r2);

    for(int i = 1; i <= n; i++)
    {
        if(i != r2)
            cout << answPi[i] << " ";
    }


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