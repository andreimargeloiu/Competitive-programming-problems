# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
# define inf 99999999
# define NR 205
# define N 1005
using namespace std;
struct elem
{
    int x, y;
}E, a[NR], sol[N];
queue <elem> q;
queue <int> Q;
struct elem2
{
    int y, tip, cost;
}F;
vector <elem2> v[N], vt[N];
int i,j,n,m,K,nr,VV,X,Y,xf,yf,pasi;
int ap[NR][NR], dist[NR];
int dx1[]={-1,-1,0,1,1,1,0,-1};
int dy1[]={0,1,1,1,0,-1,-1,-1};
int dx2[]={-2,-1,1,2,2,1,-1,-2};
int dy2[]={1,2,2,1,-1,-2,-2,-1};
void init ()
{
    for (int i=0; i<=n+1; ++i)
        ap[i][0]=ap[i][m+1]=0;
    for (int i=0; i<=m+1; ++i)
        ap[0][i]=ap[n+1][i]=0;

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            ap[i][j]=inf;
}
void LEE1 (int l, int c, int dx[], int dy[], int limita)
{
    int la,ca,lv,cv,i;
    init();
    E.x=l; E.y=c; ap[l][c]=0;
    q.push(E);
    while (! q.empty())
    {
        E=q.front(); q.pop();
        la=E.x; ca=E.y;
        for (i=0; i<8; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (ap[lv][cv]>ap[la][ca]+1)
            {
                ap[lv][cv]=ap[la][ca]+1;
                if (ap[lv][cv]<limita)
                {
                    E.x=lv; E.y=cv;
                    q.push(E);
                }
            }
        }
    }
}
void muchii (int x, int tip)
{
    for (int j=1; j<=nr; ++j)
        if (ap[a[j].x][a[j].y])
        {
            F.y=j; F.tip=tip; F.cost=ap[a[j].x][a[j].y]; v[x].push_back(F);
            F.y=x; F.tip=tip; F.cost=ap[a[j].x][a[j].y]; vt[j].push_back(F);
        }
}
void BFS (int k)
{
    int urm, cost;
    for (int i=0; i<=nr; ++i)
        dist[i]=inf;
    dist[k]=0;
    Q.push(k);
    while (! Q.empty())
    {
        k=Q.front(); Q.pop();
        for (int i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i].y; cost=v[k][i].cost;
            if (dist[urm]>dist[k]+cost)
            {
                dist[urm]=dist[k]+cost;
                Q.push(urm);
            }
        }
    }
}
void bordare ()
{
    for (int i=0; i<=n+1; ++i)
        ap[i][0]=ap[i][m+1]=inf;
    for (int i=0; i<=m+1; ++i)
        ap[0][i]=ap[n+1][i]=inf;
}
void intoarcere (int l, int c, int dx[], int dy[], int xf, int yf, int lim)
{
    LEE1 (xf, yf, dx, dy, inf);
    bordare ();
    int i, la=l, ca=c, lv, cv;
    while (1)
    {
        if (ap[la][ca]==0) break;
        for (i=0; i<8; ++i)
        {
            lv=la+dx[i]; cv=ca+dy[i];
            if (ap[lv][cv]==ap[la][ca]-1)
            {
                sol[++VV].x=lv; sol[VV].y=cv;
                la=lv; ca=cv;
                break;
            }
        }
    }
}
int main ()
{
    freopen ("arthur.in", "r", stdin);
    freopen ("arthur.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &pasi, &nr);
    scanf ("%d%d", &X, &Y);   a[0].x=X; a[0].y=Y;
    scanf ("%d%d", &xf, &yf); a[nr+1].x=xf; a[nr+1].y=yf;

    for (i=1; i<=nr; ++i)
        scanf ("%d%d", &a[i].x, &a[i].y);
    ++nr;

    for (i=0; i<nr; ++i)
    {
        //pasi normali
        LEE1 (a[i].x, a[i].y, dx1, dy1, inf);
        muchii (i, 1);

        if (i>0)
        {
            //pasi de cal
            LEE1 (a[i].x, a[i].y, dx2, dy2, pasi);
            muchii (i, 2);
        }
    }

    BFS (0);

    printf ("%d\n", dist[nr]);
    //reconstituim drumul
    int act=nr;
    while (1)
    {
        sol[++VV].x=a[act].x; sol[VV].y=a[act].y;
        if (dist[act]==0) break;
        for (i=0; i<vt[act].size(); ++i)
        {
            int urm=vt[act][i].y, tip=vt[act][i].tip, cost=vt[act][i].cost;
            if (dist[urm]==dist[act]-cost)
            {
                if (tip==1) intoarcere (a[act].x, a[act].y, dx1, dy1, a[urm].x, a[urm].y, inf);
                       else intoarcere (a[act].x, a[act].y, dx2, dy2, a[urm].x, a[urm].y, K);
                act=urm;
                break;
            }
        }
    }
    for (i=VV; i>=1; --i)
        if (sol[i].x==sol[i-1].x && sol[i].y==sol[i-1].y) VV+=0;
            else printf ("%d %d\n", sol[i].x, sol[i].y);
    return 0;
}
