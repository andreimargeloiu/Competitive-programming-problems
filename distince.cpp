# include <fstream>
# include <algorithm>
# define NR 100005
# define mod 666013
# define LB(p) ((-p)&p)
using namespace std;
ifstream f("distincte.in");
ofstream g("distincte.out");
struct elem
{
    int ci, cs, ind, S;
}Q[NR];
bool cmp (elem x, elem y)
{
    if (x.cs>y.cs) return 0;
        else if (x.cs==y.cs && x.ci>=y.ci) return 0;
            else return 1;
}
bool cmp2 (elem x, elem y)
{
    if (x.ind>=y.ind) return 0;
                 else return 1;
}

int i,j,n,m,x,y,K;
int ant[NR], a[NR], AIB[NR];

void update (int p, int v)
{
    for(; p<=n; p+=LB(p))
    {
        AIB[p]+=v+mod;
        AIB[p]%=mod;
    }
}
int Query (int p)
{
    int rez=0;
    for(; p; p-=LB(p))
    {
        rez+=AIB[p];
        rez%=mod;
    }
    return rez;
}
int main ()
{
    f>>n>>K>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];

    for (i=1; i<=m; ++i)
    {
        f>>Q[i].ci>>Q[i].cs;
        Q[i].ind=i;
    }

    sort (Q+1, Q+m+1, cmp);

    j=1;
    for (i=1; i<=m; ++i)
    {
        while (j<=Q[i].cs)
        {
            if (ant[a[j]]) update (ant[a[j]], -a[j]);
            update (j, a[j]);
            ant[a[j]]=j;

            ++j;
        }
        Q[i].S=(Query (Q[i].cs) - Query (Q[i].ci-1) +mod) % mod;
    }

    //afisare
    sort (Q+1, Q+m+1, cmp2);
    for (i=1; i<=m; ++i)
        g<<Q[i].S<<"\n";

    return 0;
}
