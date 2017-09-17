//varianta cu coada
# include <fstream>
# include <vector>
# include <queue>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
vector <int> v[50005];
queue <int> q;
int ap[100005],grad[50005];
int i,j,n,m,x,y;
void parcurgere ()
{
    int i,x;
    while (! q.empty())
    {
        x=q.front(); q.pop();
        g<<x<<" ";
        for (i=0; i<v[x].size(); ++i)
        {
            --grad[v[x][i]];
            if (grad[v[x][i]]==0 && ap[v[x][i]]==0)
            {
                ap[v[x][i]]=1;
                q.push(v[x][i]);
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
            ap[i]=1;
            q.push(i);
            ap[i]=1;
        }
    }
    parcurgere ();
    g<<"\n";
    return 0;
}
