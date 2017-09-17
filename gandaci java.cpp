# include <fstream>
# include <cstring>
# include <vector>
# include <algorithm>
# define NR 10005
using namespace std;
ifstream f("java.in");
ofstream g("java.out");
vector <int> v[NR];
int i,j,n,m,x,y,cuplate,t,teste,sol,n2;
int M1[NR], M2[NR], ap[NR];
int match (int k)
{
    if (ap[k]==1) return 0;
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
    f>>teste;
    for (t=1; t<=teste; ++t)
    {
        memset (M1, 0, sizeof(M1));
        memset (M2, 0, sizeof(M2));

        f>>n>>n2>>m;
        for (i=1; i<=n; ++i)
            v[i].clear();

        for (i=1; i<=m; ++i)
        {
            f>>x>>y;
            v[x].push_back (y);
        }
        for (i=1; i<=n; ++i)
            sort (v[i].begin(), v[i].end());


        cuplate=1;
        while (cuplate)
        {
            cuplate=0;
            memset (ap, 0, sizeof(ap));
            for (i=1; i<=n; ++i)
                if (! M1[i]) cuplate+=match(i);
        }

        sol=0;
        for (i=1; i<=n; ++i)
            if (M1[i]) ++sol;

        g<<sol<<"\n";
    }
    return 0;
}
