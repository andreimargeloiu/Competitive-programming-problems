# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
using namespace std;
ifstream f("darb.in");
ofstream g("darb.out");
vector <int> v[100005];
int i,j,n,m,x,y,maxx,S;
int ap[100005];
void DFS (int k, int niv)
{
    ap[k]=1;
    if (niv>maxx)
    {
        maxx=niv;
        S=k;
    }
    for (int i=0; i<v[k].size(); ++i)
    {
        if (! ap[v[k][i]]) DFS (v[k][i],niv+1);
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n-1; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS (1,0);
    maxx=0; memset(ap,0,sizeof(ap));
    DFS (S,0);
    g<<maxx+1;

    return 0;
}
