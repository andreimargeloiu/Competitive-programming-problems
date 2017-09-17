# include <cstdio>
# include <string>
# include <vector>
using namespace std;

inline int min(int a, int b) { return a < b ? a : b; }

int N, A[1<<21], B[1<<21];
string S;

long long solve(void)
{
	int conf, i, j, k, a[50], b[50], nra, nrb;
	for(conf = 0; conf < (1<<(N/2)); conf++)
	{
		nra = nrb = 0;
		for(j = 0, i = N/2-1; i >= 0; i--, j++)
		 if(conf&(1<<i)) a[++nra] = S[j]-'0';
		 else b[++nrb] = S[j]-'0';
		for(k = min(nra, nrb), i = 1; i <= k; i++)
		 if(a[i] != b[i]) break;
		if(i != k+1) continue ;
		if(nra == nrb) A[0]++;
		if(nra > nrb) { int t = 0; for(j =0, i = nra; i > nrb; j++, i--) t += a[i]*(1<<j); t += (1<<j); A[t]++; }
		if(nrb > nra) { int t = 0; for(j =0, i = nrb; i > nra; j++, i--) t += b[i]*(1<<j); t += (1<<j); B[t]++; }
	}
	long long res = 0;
	for(conf = 0; conf < (1<<(N/2)); conf++)
	{
		nra = nrb = 0;
		for(j = N-1, i = 0; i < N/2; i++, j--)
		 if(conf&(1<<i)) a[++nra] = S[j]-'0';
		 else b[++nrb] = S[j]-'0';
	  	for(k = min(nra, nrb), i = 1; i <= k; i++)
	  	 if(a[i] != b[i]) break;
	  	if(i != k+1) continue ;
	  	if(nra == nrb) res = res + A[0];
	  	if(nra > nrb) { int t = 0; for(j = 0, i = nrb+1; i <= nra; i++, j++) t += a[i]*(1<<j); t += (1<<j); res = res + B[t]; }
	  	if(nrb > nra) { int t = 0; for(j = 0, i = nra+1; i <= nrb; i++, j++) t += b[i]*(1<<j); t += (1<<j); res = res + A[t]; }
	}
	return res;
}

int main(void)
{
	freopen("subsiruri2.in", "rt", stdin);
	freopen("subsiruri2.out", "wt", stdout);
	scanf("%d\n", &N);
	char c;
	for(int i = 0; i < N; i++)
	{
		scanf("%c", &c);
		if(c == 'a')
			S.push_back('1');
		else
			S.push_back('0');
	}

	printf("%lld\n", solve());
}



