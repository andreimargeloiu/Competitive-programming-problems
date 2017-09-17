# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# define M 55
# define NR (1<<20)
using namespace std;
ifstream f("boom.in");
ofstream g("boom.out");
struct elem
{
    int p, nr;
}a[M];
vector <pair<int, int> > hp; //cost, nod
int i,j,n,m,X,x,nr,COST,VV;
int C[NR], ant[NR], sarja[NR], sol[NR];
void Djikstra ()
{
    int i, nod, cost, nurm, var;
    while (1)
    {
        cost=-hp[0].first; nod=hp[0].second;
        pop_heap(hp.begin(), hp.end());
        hp.pop_back();

        if (nod==0) break;


        for (i=1; i<=m; ++i)
        {
            var=nod & a[i].nr;
            nurm=nod-var; //scadem sarjele din aceasta stare

            nurm=(nurm<<1) | (nurm>>1);
            if (nurm>=(1<<n)) nurm-=(1<<n);

            if (C[nurm]==0 || C[nurm]>cost+a[i].p)
            {
                ant[nurm]=nod; sarja[nurm]=i;
                C[nurm]=cost+a[i].p;

                hp.push_back(make_pair(-C[nurm], nurm));
                push_heap (hp.begin(), hp.end());
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>a[i].p>>nr; X=0;
        for (j=1; j<=nr; ++j)
        {
            f>>x; --x;
            X+=(1<<x);
        }
        a[i].nr=X;
    }

    hp.push_back(make_pair(0, (1<<n)-1));
    push_heap (hp.begin(), hp.end());

    Djikstra ();

    //refacem drumul
    int nod=0;
    while (nod!=(1<<n)-1)
    {
        sol[++VV]=sarja[nod];
        nod=ant[nod];
    }
    g<<C[0]<<"\n";
    g<<VV<<"\n";
    for (i=VV; i>=1; --i)
        g<<sol[i]<<"\n";
    return 0;
}
