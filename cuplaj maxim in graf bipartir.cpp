# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define LB(p) ((-p)&p)
# define NR 10005
# define mod 1999999973
using namespace std;
vector <int> v[NR];
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
int i,j,n,m,VV,sol,cuplate,x,y,n2;
int M1[NR], M2[NR], ap[NR];
int match (int k)
{
    if (ap[k]==VV) return 0;
    ap[k]=VV;
    for (int i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]])
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    for (int i=0; i<v[k].size(); ++i)
        if (match(M2[v[k][i]]))
        {
            M1[k]=v[k][i];
            M2[v[k][i]]=k;
            return 1;
        }
    return 0;
}
int main ()
{
    f>>n>>n2>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back (y);
    }

    cuplate=1;
    while (cuplate)
    {
        cuplate=0; ++VV;
        for (i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=match(i);
    }
    for (i=1; i<=n; ++i)
        if (M1[i]) ++sol;

    g<<sol<<"\n";
    for (i=1; i<=n; ++i)
        if (M1[i]) g<<i<<" "<<M1[i]<<"\n";


    return 0;
}
