# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# define maxx 30005
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
struct elem
{
    int e,d;
}var;
queue <int> q;
vector <elem> v[maxx];
int D[maxx];
bool ap[maxx];
int i,j,n,m,I,F,x,y,dist;
void bfs (int init)
{
    int i,j,K,VAR;
    q.push(init);
    ap[init]=1;
    while (! q.empty ())
    {
        if (D[F]!=0) break;
        init=q.front (); q.pop();
        for (i=0; i<v[init].size(); ++i)
        {
            if (ap[v[init][i].e]==0)
            {
                D[v[init][i].e]=D[init]+v[init][i].d;
                ap[v[init][i].e]=1;
                q.push(v[init][i].e);
            }
        }
    }
}
int main ()
{
    f>>n>>m>>I>>F;
    if (I>F) swap(I,F);
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>dist;
        var.e=y; var.d=dist;
        v[x].push_back(var);

        var.e=x; var.d=-dist;
        v[y].push_back(var);
    }
    bfs(I);
    g<<D[F]<<"\n";

    return 0;
}
