# include <fstream>
# include <vector>
using namespace std;
ifstream f("grarb.in");
ofstream g("grarb.out");
vector <int> v[100005];
int i,j,n,m,x,y,conexe,maxx,nr;
int ap[100005],niv[100005];
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
    {
        if (!ap[i])
        {
            ++conexe;
            DFS (i);
        }
    }
    g<<m+conexe-n<<"\n"<<conexe-1<<"\n";

    return 0;
}
