# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
vector <int> v[NR];
int i,j,n,m,x,y,cuplate,L;
int ap[NR], M1[NR], M2[NR];

int match (int k)
{
    if (ap[k]) return 0;
    ap[k]=1;
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
    f>>n>>m>>L;
    for (i=1; i<=L; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
    }
    cuplate=1;
    while (cuplate)
    {
        memset (ap, 0, sizeof(ap));
        cuplate=0;
        for (i=1; i<=n; ++i)
            if (!M1[i]) cuplate+=match(i);
    }
    int VV=0;
    for (i=1; i<=n; ++i)
        if (M1[i]) ++VV;

    g<<VV<<"\n";
    for (i=1; i<=n; ++i)
        if (M1[i]) g<<i<<" "<<M1[i]<<"\n";


    return 0;
}
