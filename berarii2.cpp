# include <fstream>
# include <vector>
# include <queue>
# define mil 1000005
using namespace std;
ifstream f("berarii2.in");
ofstream g("berarii2.out");
vector <int> v[mil];
queue <int> q;
int i,j,n,m,x,y,p;
bool bere[mil],ap[mil];
void BFS ()
{
    int i,k;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            if (! ap[v[k][i]])
            {
                ap[v[k][i]]=1; bere[v[k][i]]=1;
                q.push(v[k][i]); ++p;
            }
        }
    }
}
int main ()
{
    f>>n>>m>>p;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[y].push_back(x);
    }
    for (i=1; i<=p; ++i)
    {
        f>>x;
        q.push(x); ap[x]=1; bere[x]=1;
    }
    BFS ();
    g<<n-p<<"\n";
    for (i=1; i<=n; ++i)
        if (! bere[i]) g<<i<<"\n";

    return 0;
}
