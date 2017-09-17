# include <fstream>
# include <algorithm>
# include <vector>
# define NR 100005
# define H 200
using namespace std;
ifstream f("lca.in");
ofstream g("lca.out");
vector <int> v[NR];

int i,j,n,m,k,L,VV,Q,x,y;
int poz[NR], niv[NR], T[NR], T2[NR];

void DFS (int k, int nivel, int tata)
{
    T2[k]=tata; niv[k]=nivel;

    if (nivel%H==0) tata=k;

    for (int i=0; i<v[k].size(); ++i)
        DFS (v[k][i], nivel+1, tata);
}
int main ()
{
    f>>n>>Q;
    for (i=2; i<=n; ++i)
    {
        f>>x; T[i]=x;
        v[x].push_back(i);
    }

    DFS (1, 0, 0);

    for (i=1; i<=Q; ++i)
    {
        f>>x>>y;
        while (T2[x]!=T2[y])
        {
            if (niv[x]<niv[y]) y=T2[y];
                          else x=T2[x];
        }
        while (x!=y)
        {
            if (niv[x]<niv[y]) y=T[y];
                          else x=T[x];
        }
        g<<x<<"\n";
    }

    return 0;
}
