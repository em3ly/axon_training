/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: F - Missile Silos
	Online Judge: codeforces.com
	Idea: Dijkstra, then check edges
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

class Edge
{
public:
    int from, to;
    ll cost;
    Edge(){}
    Edge(int f, int t, ll c)
    {from = f; to = t; cost = c;}
};

int n, m, s;
ll l;
vector<Edge> adj[lim];
vector<Edge> edges;

// >> DIJKSTRA
ll di[lim];
int pi[lim];
bool taken[lim];

bool scanned[lim];

void ISS()
{
    // ISS
    for(int i = 0; i <= n; i++)
    {
        di[i] = inf;
        taken[i] = false;
        pi[i] = -1;
    }
}

void Dijkstra(int st)
{
    ISS();

    di[st] = 0;
    pi[st] = -1;

    priority_queue<pair<ll, ll> > pq;

    int idx = st;
    while(idx != -1)
    {
        taken[idx] = true;
        // for each adjacent node
        for(int i = 0; i < adj[idx].size(); i++)
        {
            Edge * e = &adj[idx][i];
            // relax the edge
            if(di[e->to] > di[idx] + e->cost)
            {
                di[e->to] = di[idx] + e->cost;
                pi[e->to] = idx;
                // add to the queue
                pq.push(mkp(-di[e->to], e->to));
            }
        }
        // take out until getting a non-taken node
        while(pq.size() > 0 && taken[pq.top().second])
            pq.pop();
        // update idx
        idx = (pq.size() > 0) ? pq.top().second : -1;
    }
}

// << DIJKSTRA

void solve()
{
    cin >> n >> m >> s;
    // reading edges
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge * e1 = new Edge(a, b, c);
        Edge * e2 = new Edge(b, a, c);
        // add the edges to the collection
        adj[a].push_back(*e1);
        adj[b].push_back(*e2);
        // add to the vector of edges
        edges.push_back(*e1);
    }
    cin >> l;

    Dijkstra(s);

    int answ = 0;

    // for each edge
    for(int i = 0; i < edges.size(); i++)
    {
        Edge * e = &edges[i];
        int from = e->from;
        int to = e->to;
        int cost = e->cost;

        // solve problem here

        // if this edge describes a patternhood
        if(pi[from] == to || pi[to] == from)
        {
            // swap from and to
            if(pi[from] == to)
                swap(from, to);

            if(di[from] < l && di[to] > l)
                answ++;
        }
		// other wise check if silos can be placed  (can't place more than two)
        else
        {
            int cnt = 0; // silos to place
			
			// if can be placed here
            if(l > di[from] && l < di[from] + cost)
            {
                int distFrom = l - di[from];
                int distTo = cost - distFrom;
				// if the distance to To doesn't make it nearer to To than to From
                if(di[from] + distFrom <= di[to] + distTo)
                    cnt++;
            }
            if(l > di[to] && l < di[to] + cost)
            {
                int distTo = l - di[to];
                int distFrom = cost - distTo;
				// if the distance to From doesn't make it nearer to From than to To
                if(di[to] + distTo < di[from] + distFrom)
                    cnt++;
				// if is the same distance
                else if(di[to] + distTo == di[from] + distFrom)
                {
                    cnt = 1;
                }
            }
            answ += cnt;
        }
    }

    for(int i = 1; i <= n; i++)
        if(di[i] == l)
            answ++;

    // print answer
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