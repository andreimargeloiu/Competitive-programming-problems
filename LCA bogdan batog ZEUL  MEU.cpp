# include <fstream>
# include <algorithm>
# include <vector>
# define ZEU 200
# define NR 100005
using namespace std;
ifstream f("lca.in");
ofstream g("lca.out");
vector <int> v[NR];
int i,j,n,m,x,y,Q;
int niv[NR], T[NR], T2[NR];
void DFS (int k, int tata, int nivel)
{
    T2[k]=tata; niv[k]=nivel;
    if (nivel%ZEU==0) tata=k;
    for (int i=0; i<v[k].size(); ++i)
        DFS (v[k][i], tata, nivel+1);
}
int main ()
{
    f>>n>>Q;
    for (i=2; i<=n; ++i)
    {
        f>>T[i];
        v[T[i]].push_back(i);
    }
    DFS (1, 0, 0);

    for (i=1; i<=Q; ++i)
    {
        f>>x>>y;

        while (T2[x]!=T2[y])
        {
            if(niv[x] > niv[y]) x=T2[x];
                else y=T2[y];
        }
        while(x != y)
        {
            if(niv[x] > niv[y]) x=T[x];
                else y=T[y];
        }
        g<<x<<"\n";
    }

    return 0;
}
