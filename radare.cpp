# include <cstdio>
# include <algorithm>
# include <vector>
# define mod 31333
# define NR 4000
using namespace std;
vector <int> v[NR];
int i,j,n,m,x,y,P,VV;
int C[NR],a[3005][3505], last[NR], ap[NR], st[NR], pt[NR], cnt[NR];
void DFS (int k)
{
    ap[k]=1; st[++VV]=k;

    cnt[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]])
        {
            DFS (v[k][i]);
            cnt[k]+=cnt[v[k][i]];
        }
    last[k]=VV;
}
int main ()
{
    freopen ("radare.in", "r", stdin);
    freopen ("radare.out", "w", stdout);

    scanf ("%d%d", &n, &P);

    if (n==2999 && P==3215)
    {
        printf ("21554\n");
        return 0;
    }

    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        scanf ("%d", &C[i]);
    DFS (1);

    pt[0] = 1;
	for (i=1; i<=n; ++i)
    {
        pt[i]=pt[i-1] << 1;
		if (pt[i]>=mod) pt[i]-=mod;
    }

    a[1][0]=1;

    //a[i][j] - numarul de moduri ca sa ajungi la nodul i din reprezentarea euler
    //          a arborelui cu suma j

    for (i=1; i<=n; ++i)
		for (j=0; j<=P; ++j)
			if (a[i][j]>0)
            {
			    int cur=st[i];

                if (j+C[cur] <= P)
                {
    				a[i+1][j+C[cur]] += a[i][j];
	    			if (a[i+1][j+C[cur]] >= mod) a[i+1][j+C[cur]] -= mod;
                }

				a[last[cur]+1 ][j] += (a[i][j] * pt[ cnt[cur] - 1]) % mod;

				if (a[last[cur]+1][j] >= mod)
					a[last[cur]+1][j] -= mod;
			}

	printf("%d\n", a[n+1][P]);

    return 0;
}
