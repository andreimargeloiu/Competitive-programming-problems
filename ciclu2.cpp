# include <fstream>
# include <vector>
using namespace std;
ifstream f("ciclu2.in");
ofstream g("ciclu2.out");
struct elem
{
    int y,nr;
}E;
vector <elem> v[500];
int i,j,n,m,x,y,K,l,VV,ok,L;
int ap[500], luat[500];
void DFS (int k, int l)
{
    if (l>=L || ok) return;
    ++luat[k];
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i].nr])
        {
            ap[v[k][i].nr]=1;

            if(v[k][i].y==x && luat[v[k][i].y] && l+1==L)
            {
                ok=1;
            }

            DFS (v[k][i].y, l+1);

            ap[v[k][i].nr]=0;
        }
    --luat[k];
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y; E.nr=i;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    f>>K;
    for (i=1; i<=K; ++i)
    {
        ok=0; f>>x>>L;

        DFS (x,0);

        g<<ok<<"\n";
    }


    return 0;
}
