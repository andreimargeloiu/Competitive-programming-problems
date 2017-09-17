# include <fstream>
# include <vector>
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
vector <int> v[10005];
int i,j,n,m,e,x,y,VV,sol,gasit;
int M1[10005], M2[10005], used[10005];
int match (int k)
{
    int i;
    if (used[k]==VV) return 0;
    used[k]=VV;
    for (i=0; i<v[k].size(); ++i)
        if (! M2[v[k][i]])
        {
            M1[k]=v[k][i]; M2[v[k][i]]=k;
            return 1;
        }
    for (i=0; i<v[k].size(); ++i)
    {
        if (match(M2[v[k][i]]))
        {
            M1[k]=v[k][i]; M2[v[k][i]]=k;
            return 1;
        }
    }
    return 0;
}
int main ()
{
    f>>n>>m>>e;
    for (i=1; i<=e; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
    }
    gasit=1;
    while (gasit)
    {
        gasit=0; ++VV;
        for (i=1; i<=n; ++i)
            if (!M1[i]) gasit+=match(i);

    }
    for (i=1; i<=n; ++i)
        if (M1[i]) ++sol;

    g<<sol<<"\n";
    for (i=1; i<=n; ++i)
        if (M1[i]) g<<i<<" "<<M1[i]<<"\n";
    return 0;
}
