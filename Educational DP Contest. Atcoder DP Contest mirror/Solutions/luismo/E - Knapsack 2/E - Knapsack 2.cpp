/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: E - Knapsack 2
	Online Judge:
	Idea: Knapsack Variation
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

ll N, W;
ll vi[200];
ll wi[200];

ll dp[lim][200];
bool mark[lim][200];

ll DynamicProgramming(int V, int idx)
{
    if(V == 0)
       return 0;

    if(idx == 0)
        return inf;

    if(mark[V][idx])
        return dp[V][idx];

    mark[V][idx] = true;

    ll curr = inf;

    if(V - vi[idx] >= 0)
    {
        ll aux = DynamicProgramming(V - vi[idx], idx - 1);
        curr = wi[idx] + aux;
    }
    ll aux = DynamicProgramming(V, idx - 1);

    curr = min(curr, aux);

    // updating dp state
    dp[V][idx] = curr;
    return curr;
}


void solve()
{
    cin >> N >> W;

    for(int i = 1; i <= N; i++)
    {
        cin >> wi[i] >> vi[i];
    }

    ll answ = 0;
    for(int i = 1; i <= 100003; i++)
    {
        if(i == 30)
        {

            int k = max(5, 9);
        }

        ll aux = DynamicProgramming(i, N);
        if(aux <= W)
        {
            // cout << aux << endl;
            answ = i;
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