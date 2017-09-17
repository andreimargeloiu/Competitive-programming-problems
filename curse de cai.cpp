# include <fstream>
# include <algorithm>
# define inf 999999999
# define NR 1005
using namespace std;
ifstream f("cai.in");
ofstream g("cai.out");
int i,j,n,m,maxx,ci,cs,t,o;
int G[NR], I[NR], cost[NR][NR];
bool cmp (int x, int y)
{
    if (x<=y) return 0;
    else return 1;
}
int meci (int gigel, int ionel)
{
    if (G[gigel]>I[ionel]) return 200;
    else if (G[gigel]==I[ionel]) return 0;
    else return -200;
}
void dinamica ()
{
    int i,k,act; maxx=-inf;
    //cost[i][j] - castigul maxim pe care il face gigel si mai ramane cu cainii de la i la j
    for (k=n-1; k>=1; --k)
        for (i=1; i<=n; ++i)
        {
            ci=i; cs=i+k-1;
            if (1<=ci && cs<=n)
            {
                act=(ci-1)+(n-cs);
                cost[ci][cs]=max (cost[ci-1][cs] + meci(ci-1, act), cost[ci][cs+1] + meci(cs+1, act));

                if (ci==cs) maxx=max (maxx, cost[ci][cs] + meci(ci, act+1));
            }
        }
}
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n;
        G[n+1]=I[n+1]=0;
        for (i=1; i<=n; ++i)
        {
            cost[0][i]=cost[i][n+1]=-inf;
            for (j=1; j<=n; ++j)
                cost[i][j]=0;
        }

        for (i=1; i<=n; ++i) f>>G[i];
        for (i=1; i<=n; ++i) f>>I[i];

        if (n==1)
        {
            g<<meci (1,1);
            continue;
        }

        sort (G+1, G+n+1, cmp);
        sort (I+1, I+n+1, cmp);

        dinamica ();
        g<<maxx<<"\n";
    }
    return 0;
}
