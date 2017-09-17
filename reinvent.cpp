# include <cstdio>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;
vector <int> v[100005];
queue <int> q;
int i,j,n,m,X,x,y,minn,var;
int NR[100005],tata[100005];
void BFS ()
{
    int i,k;
    minn=100000000;
    while (! q.empty())
    {
         k=q.front (); q.pop();
         for (i=0; i<v[k].size(); ++i)
         {
             if (NR[v[k][i]]==0)
             {
                 NR[v[k][i]]=NR[k]+1;
                 tata[v[k][i]]=tata[k];
                 q.push(v[k][i]);
             }
             else {
                      if (tata[v[k][i]]!=tata[k]) minn=min(minn, NR[k]+NR[v[k][i]]-1);
                  }
         }
    }
}
int main ()
{
    freopen ("reinvent.in", "r", stdin);
    freopen ("reinvent.out", "w", stdout);
    scanf ("%d%d%d", &n, &m, &X);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (i=1; i<=X; ++i)
    {
        scanf ("%d", &var);
        NR[var]=1; tata[var]=var;
        q.push(var);
    }
    BFS();
    printf ("%d\n", minn);
    return 0;
}
