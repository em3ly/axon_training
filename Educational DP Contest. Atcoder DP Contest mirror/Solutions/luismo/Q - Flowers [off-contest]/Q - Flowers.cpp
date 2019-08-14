/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: Q - Flowers
	Online Judge: 
	Idea: LIS variation. NlogN using a SegmentTree
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

int N;
ll hi[lim];
ll ai[lim];


// SegmentTree
ll t[lim << 2];
void update(int idx, int L, int R, int ii, ll upd)
{
	if(L == R)
	{
		t[idx] = upd;
		return;
	}
	int le = 2*idx + 1, ri = le + 1, mid = (L + R) / 2;
	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else update(ri, mid + 1, R, ii, upd);
	//
	t[idx] = max(t[le], t[ri]);
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	if(L >= QL && R <= QR)
	{
		return t[idx];
	}
	if(L > QR || R < QL)
		return 0;
	int le = 2*idx + 1, ri = le + 1, mid = (L + R) / 2;
	ll a1 = retrieve(le, L, mid, QL, QR);
	ll a2 = retrieve(ri, mid + 1, R, QL, QR);
	//
	return max(a1, a2);
}
// << SegmentTree

void solve()
{
	cin >> N;
	for(int i = 0; i < N; i++)	
		cin >> hi[i];
	
	for(int i = 0; i < N; i++)
		cin >> ai[i];

	ll answ = 0;
	// linear scan
	for(int i = 0; i < N; i++)
	{
		ll mx = retrieve(0, 0, N, 0, hi[i] - 1);
		ll upd = mx + ai[i];
		update(0, 0, N, hi[i], upd);
		answ = max(answ, upd);
	}
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
