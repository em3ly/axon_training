/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: H - Grid 1
	Online Judge:
	Idea: DP on Matrix
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
const int lim = 2e3 + 2;

int H, W;
string str;
int mt[lim][lim];
ll paths[lim][lim];

void solve()
{
    cin >> H >> W;
    for(int i = 0; i < H; i++)
    {
        cin >> str;
        for(int j = 0; j < W; j++)
        {
            if(str[j] == '#')
                mt[i][j] = 1;
        }
    }

    paths[0][0] = 1;

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            paths[i][j] %= mod;
            if(mt[i][j] == 0)
            {
                paths[i][j+1] += paths[i][j];
                paths[i+1][j] += paths[i][j];
            }
        }
    }

    cout << paths[H-1][W-1] << endl;
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