# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
ifstream f("traseu1.in");
ofstream g("traseu1.out");
struct elem
{
    int x, dist;
}a;
vector <elem> v[505];
queue <int> q;
int minn[505];
int i,j,X,Y,n,m,x,y;
void BFS ()
{
    int k;
    while (!q.empty())
    {
        k=q.front(); q.pop();
        for (int i=0; i<v[k].size(); ++i)
        {
            if (max(v[k][i].dist,minn[k])<minn[v[k][i].x])
            {
                minn[v[k][i].x]=max(v[k][i].dist,minn[k]);
                q.push(v[k][i].x);
            }
        }
    }
}
int main ()
{
    freopen ("traseu1.in", "r", stdin);
    freopen ("traseu1.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &a.dist);
        a.x=y;
        v[x].push_back(a);
        a.x=x;
        v[y].push_back(a);
    }
    scanf ("%d%d", &X, &Y);
    for (i=1; i<=n; ++i)
        if (i!=X) minn[i]=999999;
    q.push(X);
    BFS();
    printf("%d\n", minn[Y]);
    return 0;
}
