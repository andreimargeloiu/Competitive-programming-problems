# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 100005
using namespace std;
ifstream f("victorie.in");
ofstream g("victorie.out");
vector <int> v[NR], arb[NR];
struct elem
{
    int k, suma;
}E;
queue <elem> q;
int i,j,n,m,x,y,VV;
int ap[NR], T[NR], niv[NR], sol[NR], baga[NR], scoate[NR], S[NR];

void DFS (int k, int nivel, int tata)
{
    int i,urm;
    niv[k]=nivel; ap[k]=1;

    for (i=0; i<v[k].size(); ++i)
    {
        urm=v[k][i];
        if (urm!=tata)
        {
            if (! ap[urm])
            {
                arb[k].push_back(urm);
                arb[urm].push_back(k);

                DFS (urm, nivel+1, k);
            }
            else {
                     if ((nivel-niv[urm])%2==0 && niv[urm]<nivel)
                     {
                         ++baga[k];
                         --scoate[urm];
                     }
                 }
        }
    }
}
void DFSarb (int k, int tata)
{
    int i,urm;
    S[k]+=baga[k];
    for (i=0; i<arb[k].size(); ++i)
    {
        urm=arb[k][i];
        if (urm!=tata)
        {
            DFSarb (urm, k);
            S[k]+=S[urm];
        }
    }
    if (S[k])
    {
        sol[++VV]=k;
    }
    S[k]-=scoate[k];
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        if (x==y) continue;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS (1, 1, 0);

    //sortaret

    DFSarb (1, 0);

    sort (sol+1, sol+VV+1);

    g<<VV<<"\n";
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<" ";
    g<<"\n";

    return 0;
}
