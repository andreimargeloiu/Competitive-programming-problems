# include <cstdio>
# include <cmath>
# include <vector>
# include <algorithm>
using namespace std;
const double pi = acos(-1);
int i,j,N,X,Y,st,dr,nr;
int x[100010], y[100010];
double unghi[100010];
int main()
{
	freopen("hawaii.in", "r", stdin);
	freopen("hawaii.out", "w", stdout);
	scanf("%d%d%d", &N, &X, &Y);
	for (i=1; i<=N; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		double u=-1;
		u=atan2(y[i]-Y, x[i]-X);//fac arctg pt a le sorta
		if (u<0) u+=2*pi;
		unghi[i]=u;
	}
	sort(unghi+1, unghi+N+1);//sortez
	for (i=N+1; i<=N+N; ++i)
        unghi[i]=unghi[i-N]+2*pi;
	dr=2;
	long long rez=0;
	for (st=1; st<=N; ++st)
	{
		while (unghi[dr]<unghi[st]+pi) dr++;
		if (st<dr) nr=dr-st-1;
		else nr=N-st+dr;
		rez+=(long long)nr*(nr-1)/2;
	}
	long long VV=(long long)(N)*(N-1)*(N-2)/6;
	printf("%lld\n", VV-rez);
	return 0;
}

