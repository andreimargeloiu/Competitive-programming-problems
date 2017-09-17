# include <fstream>
# include <algorithm>
# define inf 99999999
# define NR 500
using namespace std;
ifstream f("petrom.in");
ofstream g("petrom.out");
int i,j,n,m,k,K,minn,I;
int cost[NR][NR], a[NR][NR], dist[NR], front[NR], back[NR], inapoi[NR][NR], sol[NR];
void init ()
{
    int i,j,k;
    //front
    for (i=1; i<=n; ++i)
        for (j=1; j<i; ++j)
            front[i]+=(dist[i]-dist[j]);

    //back
    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
            back[i]+=(dist[j]-dist[i]);

    for (i=1; i<=n; ++i)
        for (j=1; j<=K; ++j)
            a[i][j]=inf;

    for (i=1; i<=n; ++i)
    {
        cost[i][i+1]=0;
        for (j=i+2; j<=n; ++j)
            for (k=i+1; k<=j-1; ++k)
            {
                if (dist[k]-dist[i]<dist[j]-dist[k]) cost[i][j]+=(dist[k]-dist[i]);
                    else cost[i][j]+=(dist[j]-dist[k]);
            }
    }
}
int main ()
{
    int i,j,k;
    f>>n>>K;
    for (i=1; i<=n; ++i)
        f>>dist[i];

    init ();

    //a[i][j]-costul pentru a alimenta pana la benzinaria i cu j depozite
    //prima benzinarie
    for (i=1; i<=n; ++i)
        a[i][1]=front[i];

    for (j=2; j<=K; ++j)//pentru fiecare depozit format
    {
        for (i=2; i<=n; ++i)//pentru fiecare benzinarie
        {
            for (k=i-1; k>=j-1; --k)
            {
                if (a[i][j]>a[k][j-1]+cost[k][i])
                {
                    a[i][j]=a[k][j-1]+cost[k][i];
                    inapoi[i][j]=k;
                }
            }
        }
    }

    for (i=1; i<=n; ++i)
        a[i][K]+=back[i];

    minn=inf; I=0;
    for (i=1; i<=n; ++i) //caut minimul;
        if (a[i][K]<minn) minn=a[i][K], I=i;

    for (i=K; i>=1; --i)
    {
        sol[i]=I;
        I=inapoi[I][i];
    }

    g<<minn<<"\n";
    for (i=1; i<=K; ++i)
        g<<sol[i]<<"\n";

    return 0;
}
