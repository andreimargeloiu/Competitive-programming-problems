# include <fstream>
# include <algorithm>
# define NR 305
# define inf 999999999
using namespace std;
ifstream f("livada2.in");
ofstream g("livada2.out");
int i,j,n,m,t,o,maxx,sol,costmax,ci,cs,S;
int a[NR][NR], cost[NR][NR], dr[NR][NR], st[NR][NR], mat[NR][NR], sst[NR], sdr[NR];
int maxim (int a, int b, int c, int d)
{
    int maxx1=max(a, b);
    int maxx2=max(c, d);
    return max(maxx1, maxx2);
}
int main ()
{
    f>>t;

    //maxim [i][j]- maximul pe care il pot face intre i si j
    //sus[j] - maximul unei bari care il cuprinde pe j
    for (o=1; o<=t; ++o)
    {
        f>>n>>m; sol=-inf;
        for (i=1; i<=n; ++i)
            for (j=1; j<=m; ++j)
                f>>a[i][j];

        for (i=1; i<=n; ++i)
        {
            for (ci=1; ci<=m; ++ci)
            {
                S=0; maxsus=0;
                for (cs=ci; cs<=m; ++cs)
                {
                    S=S+a[i][cs]; maxsus=max(maxsus, sus[cs]);
                    maxim[ci][cs]=S+maxsus;
                    sol=max(sol, maxim[ci][cs]);
                }
            }

            for (ci=1; ci<=m; ++ci)
            {
                S=0; maxsus=0;
                for (cs=ci; cs<=m; ++cs)
                {
                    S=S+a[i][cs]; maxsus=max(maxsus, sus[cs]);
                    maxim[ci][cs]=S+maxsus;
                    sol=max(sol, maxim[ci][cs]);
                }
            }
        }

        g<<sol<<"\n";
    }


    return 0;
}
