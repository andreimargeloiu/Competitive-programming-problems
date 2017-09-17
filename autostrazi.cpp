# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 105
# define mod 30011
using namespace std;
vector <int> v[NR];
int i,j,n,m,S,K,x,y,VV;
int cost[NR],ap[NR],a[NR][NR],suma[NR][NR];
void DFS (int k)
{
    int i,j,o,son,Svar=0,ok=0;

    ap[k]=1; a[k][0]=1; suma[k][0]=1;

    for (i=0; i<v[k].size(); ++i)
    {
        son=v[k][i];
        if (! ap[son])
        {
            DFS (son);

            for (o=S; o>=0; --o) //pentru fiecare suma anterioara
            {
                for (j=1; j<=VV; ++j) //mai adaugam muchia actuala
                    if (o-cost[j]>=0) a[son][o]+=a[son][o-cost[j]];

                a[son][o]%=mod;
            }

            for (j=1; j<=S; ++j) //din a[son]
                for (o=0; o<=S-j; ++o)
                {
                    a[k][max(o,j)]+=(a[son][j]*suma[k][o]);
                    a[k][max(o,j)]%=mod;
                }
            for (j=1; j<=S; ++j)
                suma[k][j]=a[k][j];
            suma[k][0]=a[k][0]=1;
        }
    }
}
int main ()
{
    freopen ("autostrazi.in", "r", stdin);
    freopen ("autostrazi.out", "w", stdout);
    scanf ("%d%d%d", &n, &S, &K);
    for (i=1; i<=K; ++i)
    {
        scanf ("%d", &x);
        if (x<=S) cost[++VV]=x;
    }
    for (i=1; i<n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS (1);
    VV=0;
    for (i=0; i<=S; ++i)
        VV+=a[1][i];
    printf ("%d\n", VV%mod);

    return 0;
}
