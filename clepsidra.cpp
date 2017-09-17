# include <fstream>
# include <algorithm>
# include <vector>
# define NR 200005
# define mod 666013
using namespace std;
ifstream f("clepsidra.in");
ofstream g("clepsidra.out");
vector <int> v[NR];
int i,j,n,m,x,y,S,fii;
int ap[NR], T[NR], put[NR], minn[NR], niv[NR], sol[NR];
void puteri ()
{
    put[0]=1;
    for (int i=1; i<=n; ++i)
    {
        put[i]=put[i-1]*2;
        if (put[i]>=mod) put[i]-=mod;
    }
}
void DFS (int k, int nivel, int tata)
{
    ap[k]=1; niv[k]=nivel; T[k]=tata; minn[k]=nivel;

    int ok=0, conexe=v[k].size();
    for (int i=0; i<v[k].size(); ++i)
    {
        int urm=v[k][i];
        if (urm!=tata)
        {
            if (! ap[urm])
            {
                if (k==S) ++fii;
                DFS (urm, nivel+1, k);

                if (minn[urm]<nivel) --conexe;
                                else ok=1;

                minn[k]=min(minn[k], minn[urm]);
            }
            else minn[k]=min(minn[k], niv[urm]), --conexe;
        }
    }
    if (k==S)
    {
        if (fii>1) sol[k]=(put[fii]-2)%mod;
    }
    else if (conexe>1)
    {
        sol[k]=(put[conexe]-2)%mod;
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    puteri ();

    S=1;
    DFS (S, 1, 0);

    for (i=1; i<=n; ++i)
        g<<sol[i]<<"\n";

    return 0;
}
