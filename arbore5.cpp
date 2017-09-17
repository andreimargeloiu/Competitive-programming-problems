# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 100005
using namespace std;
ifstream f("arbore5.in");
ofstream g("arbore5.out");
struct elem
{
    int y, i;
}E;
vector <elem> v[NR], a[NR];
queue <int> q;
int i,j,n,m,x,y,S,nrsol,VV;
int T[NR], ap[NR], sol[NR], maxx[NR], in[NR], var[NR];
void DFS (int k, int tata, int I)
{
    ap[k]=++VV; T[k]=tata;
    for (int i=0; i<v[k].size(); ++i)
    {
        if (v[k][i].y!=tata)
        {
            DFS(v[k][i].y, k, v[k][i].i);
            maxx[k]=max(maxx[k], ap[v[k][i].y]);
        }
    }
    E.y=tata; E.i=I;
    a[k].push_back(E); ++in[tata];
}
void sortaret ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<a[k].size(); ++i)
        {
            --in[a[k][i].y]; var[a[k][i].y]+=var[k];

            sol[a[k][i].i]=var[k];

            if (!in[a[k][i].y]) q.push(a[k][i].y);
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<n; ++i)
    {
        f>>x>>y; E.i=i;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }

    DFS (1, 0, 0); S=1;

    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        if (ap[x]>ap[y]) swap(x,y);
        if (ap[y]>maxx[x]) //daca nu se afla in subarborele sau
        {
            ++var[x]; ++var[y]; --var[S];
        }
        else //este in subarborele sau
        {
            ++var[y]; --var[x];
        }
    }

    //incepem sortarea topologica
    for (i=1; i<=n; ++i)
    {
        if (! in[i]) q.push(i);
    }
    sortaret();

    for (i=1; i<n; ++i)
        if (sol[i]%2==0) ++nrsol;

    g<<nrsol<<"\n";

    return 0;
}
