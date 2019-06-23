/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: B - Serial Time!
	Online Judge: codeforces.com
	Idea: DFS by levels. Nice problem
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
const int lim = 2e1 + 2;


int k, n, m, x, y;

int mt[lim][lim][lim];
// time
int vstm[lim][lim][lim];
// movement arrays
int xs [] = {0, 0, 1, -1};
int ys [] = {1, -1, 0, 0};

string str;

bool valid(int lev, int rw, int cl)
{
    return rw >= 0 && rw < n &&
            cl >= 0 && cl < m && mt[lev][rw][cl] && !vstm[lev][rw][cl];
}

int DFS(int lev, int rw, int cl)
{
    int ret = 1;
    vstm[lev][rw][cl] = 1;
    // for each adjacent cell
    for(int i = 0; i < 4; i++)
    {
        int nx = rw + xs[i];
        int ny = cl + ys[i];

        if(valid(lev, nx, ny))
        {
            int aux = DFS(lev, nx, ny);
            ret += aux;
        }
    }

    // if can go a level down
    if(valid(lev-1, rw, cl))
    {
        int aux = DFS(lev-1, rw, cl);
        ret += aux;
    }

    // if can go a level up
    if(valid(lev+1, rw, cl))
    {
        int aux = DFS(lev+1, rw, cl);
        ret += aux;
    }
    return ret;
}


void solve()
{
    cin >> k >> n >> m;

    for(int lev = 1; lev <= k; lev++)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> str;
            for(int j = 0; j < m; j++)
            {
                // obstacle
                if(str[j] == '.')
                    mt[lev][i][j] = 1;
            }
        }
    }
    cin >> x >> y;
    x--; y--;

    int answ = 0;

    int k = DFS(1, x, y);

    answ += k;

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