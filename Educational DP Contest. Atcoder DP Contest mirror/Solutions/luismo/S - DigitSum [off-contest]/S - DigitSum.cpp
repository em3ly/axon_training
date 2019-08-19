/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: S - DigitSum
	Online Judge: AtCoder
	Idea: Digit DP. dp[i][j] - the amount of number-strings of lenght i such that the digSum of its digits leaves remainder rem with D.
	Numbers with leading zeros are managed as if such zeroes were "trimmed" eg. 00023 would mean
	23
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
const int lim = 2e4 + 2;


string str;
ll D;


// dp[i][j] - the amount of number-strings of lenght i such that the digSum of its digits leaves remainder rem with D
ll dp[lim][102];
bool mark[lim][102];

ll DynamicProgramming(int len, int rem)
{	
	if(len == 1)
	{		
		int cnt = 0;		
		for(int i = 0; i <= 9; i++)
			if(i % D == rem)
				cnt++;
		return cnt;
	}

	if(mark[len][rem])
		return dp[len][rem];

	// for each possible ending digit
	for(int dig = 0; dig <= 9; dig++)
	{
		int r = dig % D;
		int rr = (rem - r + D) % D; 
		ll k = DynamicProgramming(len - 1, rr);

		dp[len][rem] = (dp[len][rem] + k) % mod;
	}

	mark[len][rem] = true;
	return dp[len][rem];
}


void BruteForce()
{
	if(str.size() > 4)
		return;
	ll N = 0;
	ll ten = 1;
	for(int i = 0; i < str.size(); i++)
	{
		int idx = str.size() - 1 - i;
		N += ten * (str[idx] - '0');
		ten*= 10;
	}
	// BRUTE FORCE
	ll sansw = 0;
	for(int i = 1; i <= N; i++)
	{
		ll digSum = 0;
		int k = i;
		while(k > 0)
		{
			digSum += k % 10;
			k /= 10;
		}

		if(digSum % D == 0)
			sansw++;

		sansw %= mod;
	}

	cout << sansw << endl;
}

void solve()
{
	cin >> str >> D;
	// lenght of the number
	int sz = str.size();

	ll answ = 0;
		
	int digSum = 0; // keeps the sum of the first digits from left to right
	for(int i = 0; i < sz - 1; i++)
	{
		// current digit
		int d = str[i]-'0';
		// for each possible value (from 0 to d - 1)
		for(int j = 0; j < d; j++)
		{
			// remainder to search
			int r = (digSum + j) % D;

			ll k = DynamicProgramming(sz - 1 - i, (D - r)%D);			
			// update answer
			answ = (answ + k) % mod;
		}
		// add the current digit to the sum
		digSum = (digSum + d) % mod;
	}
	// checking the sum with the last digit
	for(int i = 0; i <= str[sz-1]-'0'; i++)
		if((digSum + i) % D == 0)
			answ++;
	// removing case 00000000....0000
	answ--;
	// printing answer
	cout << (answ + mod) % mod << endl;

	//cerr << "Brute Force Solution:" << endl;
	//BruteForce();
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
