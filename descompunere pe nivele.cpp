//varianta cu coada
# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
ifstream f("desc.in");
ofstream g("desc.out");
vector <int> v[50005],sol[50005];
struct elem
{
    int elem, niv;
}X,Y;
queue <elem> q;
int ap[100005],grad[50005];
int i,j,n,m,x,y,maxx;
void parcurgere ()
{
    int i,x;
    while (! q.empty())
    {
        X=q.front(); q.pop();
        maxx=max(maxx, X.niv);
        sol[X.niv].push_back(X.elem);
        x=X.elem;
        for (i=0; i<v[x].size(); ++i)
        {
            --grad[v[x][i]];
            if (grad[v[x][i]]==0 && ap[v[x][i]]==0)
            {
                ap[v[x][i]]=1;
                Y.elem=v[x][i]; Y.niv=X.niv+1;
                q.push(Y);
            }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        ++grad[y];
        v[x].push_back(y);
    }
    for (i=1; i<=n; ++i)
    {
        if (grad[i]==0)
        {
            X.elem=i; X.niv=1;
            q.push(X);
            ap[i]=1;
        }
    }
    parcurgere ();
    for (i=1; i<=maxx; ++i)
    {
        g<<i<<": ";
        for (j=0; j<sol[i].size(); ++j)
            g<<sol[i][j]<<" ";
        g<<"\n";
    }
    return 0;
}
