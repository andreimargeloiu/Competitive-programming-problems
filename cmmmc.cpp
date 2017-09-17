//Code by Patcas Csaba
//Time complexity: O(MAX log log MAX + sqrt(n) + 2 ^ nFactors)
//Space complexity: O(sqrt(MAX))
//Method: Erastotenes sieve + factorization + brute force
//Implementation time: 45 minutes

#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <list>

#include <numeric>
#include <algorithm>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define LL long long
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define VB vector <bool>
#define VI vector <int>
#define VD vector <double>
#define VS vector <string>
#define VLL vector <LL>
#define VPII vector <pair <int, int> >
#define VVI vector < VI >
#define VVB vector < VB >

#define FORN(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORI(it, X) for(__typeof((X).begin()) it = (X).begin(); it !=(X).end(); ++it)
#define REPEAT do{
#define UNTIL(x) }while(!(x));

#define SZ size()
#define BG begin()
#define EN end()
#define CL clear()
#define X first
#define Y second
#define RS resize
#define PB push_back
#define MP make_pair
#define ALL(x) x.begin(), x.end()

#define IN_FILE "cmmmc.in"
#define OUT_FILE "cmmmc.out"
#define MAX 2000000000

ifstream fin(IN_FILE);
ofstream fout(OUT_FILE);

int test, nSol;
LL n;
VPII factors;
VB isPrime;
VI primes;
VLL compacted;

void Erast()
{
	int gyok = sqrt(double(MAX));
	isPrime.RS(gyok + 1, true);
	FOR(i, 2, gyok >> 1)
		if (isPrime[i])
			for(int j = i + i; j <= gyok; j += i) isPrime[j] = false;
	FOR(i, 2, gyok)
		if (isPrime[i]) primes.PB(i);
}

void BuildFactors()
{
	factors.CL, compacted.CL;
	LL aux = n;
	int iPrime = 0, gyok = sqrt(double(n));
	while (iPrime < primes.SZ && aux > 1)
	{
		int exponent = 0, prime = primes[iPrime];
		if (prime > gyok) break;
		while (!(aux % prime))
		{
			++exponent;
			aux /= prime;
		}
		if (exponent) factors.PB(MP(prime, exponent));
		if (aux < isPrime.SZ && isPrime[aux]) break;
		++iPrime;
	}
	if (aux > 1) factors.PB(MP(aux, 1));
	FORN(i, factors.SZ)
	{
		LL factor = factors[i].X;
		FOR(j, 2, factors[i].Y) factor *= factors[i].X;
		compacted.PB(factor);
	}
}

PLL Solve()
{
	nSol = 1;
	FORN(i, factors.SZ) nSol *= (2*factors[i].Y + 1);
	nSol = nSol / 2 + 1;
	PLL ans;
	LL minSum = (LL)MAX + MAX + 1;
	FORN(i, 1 << factors.SZ)
	{
		LL x = 1, y = 1;
		FORN(j, factors.SZ)
			if (i & (1 << j)) x *= compacted[j];
			else y *= compacted[j];
		if (minSum > x + y)
		{
			minSum = x + y;
			ans = MP(x, y);
		}
	}
	if (ans.X > ans.Y) swap(ans.X, ans.Y);
	return ans;
}

int main()
{
	Erast();

	fin >> test;
	FORN(t, test)
	{
		fin >> n;
		BuildFactors();
		PII sol = Solve();
		fout << nSol << " " << sol.X << " " << sol.Y << endl;
	}
	fin.close();
	fout.close();

	return 0;
}
