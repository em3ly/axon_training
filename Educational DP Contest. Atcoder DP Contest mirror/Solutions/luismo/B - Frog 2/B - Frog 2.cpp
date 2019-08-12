/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: B - Frog 2
	Online Judge:
	Idea: Easy DP 2
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

int N, K;
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
    
    int kidx =max(0,idx - K);
    ll aux = inf;
    for(int i = kidx; i < idx; i++)
    {
        ll curr = dp[i] + abs(hi[i] - hi[idx]);
        aux = min(aux, curr);
    }

    dp[idx] = aux;
    return dp[idx];
}


void solve()
{
    cin >> N >> K;
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