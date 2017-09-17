# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
# define inf 999999999
using namespace std;
struct elem2
{
    int k, w;
}X;
queue <elem2> q;
struct elem
{
    int y, t, w;
}E;
vector <elem> v[55];
int i,j,n,m,x,y,minn,sol,ci,cs,mij,K,VV;
int Tmin[55][1005],F[55];
int BF (int W)
{
    int i,j,k,w;
    for (i=1; i<=n; ++i)
        for (j=0; j<=W; ++j)
            Tmin[i][j]=inf;
    Tmin[1][W]=0;
    X.k=1; X.w=W;
    q.push(X);
    while (! q.empty())
    {
        X=q.front(); q.pop();
        k=X.k; w=X.w;
        if (F[k]) VV=W;
            else VV=w;
        for (i=0; i<v[k].size(); ++i)
        {
            if (VV>=v[k][i].w && Tmin[v[k][i].y][VV-v[k][i].w]>Tmin[k][w]+v[k][i].t)
            {
                Tmin[v[k][i].y][VV-v[k][i].w]=Tmin[k][w]+v[k][i].t;
                X.k=v[k][i].y; X.w=VV-v[k][i].w;
                q.push(X);
            }
        }
    }
    int minim=inf;
    for (i=0; i<=W; ++i)
        minim=min(minim, Tmin[n][i]);
    return minim;
}
int main ()
{
    freopen ("lanterna.in", "r", stdin);
    freopen ("lanterna.out", "w", stdout);
    scanf ("%d%d", &n, &K);
    for (i=1; i<=n; ++i)
        scanf ("%d", &F[i]);
    scanf ("%d", &m);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d%d%d", &x, &y, &E.t, &E.w);
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    minn=BF(K);
    ci=1; cs=K;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (BF(mij)>minn) ci=mij+1;
        else cs=mij-1,sol=mij;
    }
    printf ("%d %d\n", minn, sol);
    return 0;
}
