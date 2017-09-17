# include <fstream>
# include <algorithm>
# define NR 250005
using namespace std;
ifstream f("nessie.in");
ofstream g("nessie.out");
struct elem
{
    int x, y;
}a[NR];
bool cmp1 (elem x, elem y)
{
    if (x.y>=y.y) return 0;
             else return 1;
}
bool cmp2 (elem x, elem y)
{
    if (x.y<=y.y) return 0;
             else return 1;
}

int i,j,n,m,x,y,VV,maxx,I,minn,ci;
int aproape[NR], ap[NR], departe[NR], cost[NR];
// aproape[i] - cel mai aproapiat capat stanga al unui segment
// cu dreapta <=i

// departe[i] - cel mai indepartat stanga al unui segment care
// trece si prin i

bool verificare (int ci, int K)
{
    if (aproape[K]>=ci) return 0;
                   else return 1;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>a[i].x>>a[i].y;
        ++ap[a[i].x]; --ap[a[i].y+1];
    }
    for (i=1; i<=n; ++i)     // ap[i] - cate segmente trec simultan pe aici
        ap[i]=ap[i]+ap[i-1];

    sort (a+1, a+m+1, cmp1); //crescator dupa dreapta
    VV=1; maxx=0;
    for (i=1; i<=n; ++i)
    {
        while (a[VV].y==i && VV<=m)
        {
            maxx=max(maxx, a[VV].x);
            ++VV;
        }
        aproape[i]=maxx;
    }
    // verific daca este IMPOSIBIL -> daca un segment cuprinde complet minim doua segmente
    for (i=1; i<=m; ++i) //fiecare segment
    {
        I=aproape[a[i].y];
        I=aproape[I-1];
        if (I>=a[i].x)
        {
            g<<"IMPOSIBIL\n";
            return 0;
        }
    }

    sort (a+1, a+m+1, cmp2); //descrescator dupa dreapta
    minn=n+1; VV=1;
    // aflu minimul din aceasta pozitie, daca e liber departe[i]>i
    // adica pozitia la stanga celui mai indepartat segment pe care il intep acum
    for (i=n; i>=1; --i)
    {
        while (a[VV].y==i && VV<=m)
        {
            minn=min(minn, a[VV].x);
            ++VV;
        }
        departe[i]=minn;
    }
    // cost[i] - numarul maxim de pasi pe care ii pot face, astfel incat sa cuprind
    // toate segmentele anterioare cat si pe cele care le intersectez acum
    for (i=1; i<=n; ++i)
    {
        if (ap[i])
        {
            ci=departe[i];
            if (verificare (ci, i-1)) // daca nu este un segment cuprind in acest interval
            {
                cost[i]=1 + cost[ci-1];
            }
            else cost[i]=cost[i-1];
        }
        else cost[i]=cost[i-1]+1;
    }

    g<<cost[n]<<"\n";

    return 0;
}
