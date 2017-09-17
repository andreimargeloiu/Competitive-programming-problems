# include <cstdio>
# include <vector>
# include <cstring>
using namespace std;
struct elem
{
    int y;
    short val;
}E;
vector <elem> v[1005];
int i,j,n,m,x,y,var,nrsol,ok,V,luate;
int ap[1005],ord[1005],sol[1005];
char ch;
void DFS (int k)
{
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (!ap[v[k][i].y]) DFS(v[k][i].y);
    ord[--var]=k;
}
int main ()
{
    freopen ("honest.in", "r", stdin);
    freopen ("honest.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d %c%d", &x, &ch, &y);
        E.y=y;
        if (ch=='m') E.val=-1;
            else E.val=1;
        v[x].push_back(E);
    }
    var=n+1;
    for (i=1; i<=n; ++i)
        if (!ap[i]) DFS (i);

    sol[1]=1; luate=1;
    while (luate<n)
    {
        for (i=1; i<=n; ++i)
        {
            if (i==154)
            {
                i=i;
            }
            if (sol[i]==0)
            {
                for (j=0; j<v[i].size(); ++j)
                    if (sol[v[i][j].y]!=0) {
                                                sol[i]=sol[v[i][j].y]*v[i][j].val;
                                                ++luate;
                                                break;
                                           }

            }
            if (sol[i]!=0)
            {
                for (j=0; j<v[i].size(); ++j)
                    if (sol[v[i][j].y]==0) sol[v[i][j].y]=sol[i]*v[i][j].val,++luate;
            }
        }
    }
    ok=1;
    for (i=1; i<=n; ++i)
        if (sol[i]==1) ++nrsol;
    if (nrsol<n/2) ok=-1;
    for (i=1; i<=n; ++i)
    {
        V=sol[i]*ok;
        if (V==-1) V=0;
        printf ("%d\n", V);
    }
    return 0;
}
