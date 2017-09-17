# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
using namespace std;
vector <int> v[20000];
queue <int> q;
int ant[20000],niv[20000];
int i,j,n,m,x,y,maxx;
void BFS()
{
    int i,k;
    while (!q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            --ant[v[k][i]];
            if (ant[v[k][i]]==0)
            {
                niv[v[k][i]]=niv[k]+1;
                maxx=max(maxx, niv[v[k][i]]);
                q.push(v[k][i]);
            }
        }
    }
}
int main ()
{
    freopen ("soldati.in", "r", stdin);
    freopen ("soldati.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        ++ant[y];
    }
    for (i=1; i<=n; ++i)
        if (ant[i]==0) niv[i]=1, q.push(i);
    maxx=1; BFS();
    printf ("%d\n", maxx);
    return 0;
}
