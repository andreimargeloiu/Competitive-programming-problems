# include <fstream>
# include <algorithm>
# define NR 105
# define inf 999999999
using namespace std;
ifstream f("job.in");
ofstream g("job.out");
struct elem
{
    int dist, consum;
}a[NR];
int i,j,n,m,S,l,ci,cs,VV;
int cost[NR][NR][3], timp[NR][NR][3];
int COST (int ci, int cs, int T)
{
    int S=0;
    int minn=min(a[ci].dist, a[cs].dist), maxx=max(a[ci].dist, a[cs].dist);
    VV=maxx-minn;
    S=(maxx-minn+T);
    return S;
}
void calculeaza (int ci, int cs)
{
    int var,T,Tnew,NEW;
    //adaugam becul din stanga
    var=inf; T=0;
    if (cost[ci+1][cs][1]!=inf)
    {
        NEW=cost[ci+1][cs][1]+a[ci].consum*COST(ci, ci+1, timp[ci+1][cs][1]);
        Tnew=timp[ci+1][cs][1]+VV;
        if (var>NEW || (var==NEW && Tnew<T))
        {
            var=NEW;
            T=Tnew;
        }
    }
    //2
    if (cost[ci+1][cs][2]!=inf)
    {
        NEW=cost[ci+1][cs][2]+a[ci].consum*COST(ci, cs, timp[ci+1][cs][2]);
        Tnew=timp[ci+1][cs][2]+VV;
        if (var>NEW || (var==NEW && Tnew<T))
        {
            var=NEW;
            T=Tnew;
        }
    }
    cost[ci][cs][1]=var;
    timp[ci][cs][1]=T;

    //adaugam becul din dreapta
    var=inf; T=0;
    if (cost[ci][cs-1][1]!=inf)
    {
        NEW=cost[ci][cs-1][1]+a[cs].consum*COST(ci, cs, timp[ci][cs-1][1]);
        Tnew=timp[ci][cs-1][1]+VV;
        if (var>NEW || (var==NEW && Tnew<T))
        {
            var=NEW;
            T=Tnew;
        }
    }
    //2
    if (cost[ci][cs-1][2]!=inf)
    {
        NEW=cost[ci][cs-1][2]+a[cs].consum*COST(cs-1, cs, timp[ci][cs-1][2]);
        Tnew=timp[ci][cs-1][2]+VV;
        if (var>NEW || (var==NEW && Tnew<T))
        {
            var=NEW;
            T=Tnew;
        }
    }
    cost[ci][cs][2]=var;
    timp[ci][cs][2]=T;
}
int main ()
{
    f>>n>>S;
    for (i=1; i<=n; ++i)
        f>>a[i].dist>>a[i].consum;

    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
            cost[i][j][1]=cost[i][j][2]=inf;

    cost[S][S][1]=cost[S][S][2]=0;
    if (S<n) //dreapta
    {
        cost[S][S+1][2]=a[S+1].consum*COST(S,S+1,0);
        timp[S][S+1][2]=VV;
    }
    if (S>1) //stanga
    {
        cost[S-1][S][1]=a[S-1].consum*COST(S-1,S,0);
        timp[S-1][S][1]=VV;
    }
    for (l=3; l<=n; ++l)
    {
        for (i=1; i<=n; ++i)
        {
            ci=i; cs=i+l-1;
            if (1<=ci && cs<=n && S-l+1<=ci && ci<=S+l-1 && ci<=S && S<=cs)
                calculeaza (ci,cs);
        }
    }

    g<<min(cost[1][n][1], cost[1][n][2])<<"\n";

    return 0;
}
