# include <cstdio>
using namespace std;
int i,p,u,n,m,x,y,v[20005],nr;
int sol=0;
int main ()
{
	freopen ("politic.in", "r", stdin);
	freopen ("politic.out", "w", stdout);

	scanf("%d%d", &n, &y);
	v[++m]=1;
	for(i=1; i<n; ++i)
	{
		scanf("%d",&x);
		if(x==y+1) ++v[m];
            else v[++m]=1;
		y=x;
	}

	p=u=1; nr=v[1];
	while(u<=m)
	{
		if(nr>n/2)
		{
			sol+=m-u+1;
			nr-=v[p];
			++p;
		}
		else nr+=v[++u];
	}

	printf("%d\n%d\n", m, sol);

	return 0;
}
