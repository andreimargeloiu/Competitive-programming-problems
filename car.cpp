# include <fstream>
# include <algorithm>
# include <queue>
# include <cstring>
# define inf 999999999
using namespace std;
ifstream f("car.in");
ofstream g("car.out");
struct elem
{
    int x,y,dir;
}E;
queue <elem> q;
int i,j,n,m,x,y,X,Y,xact,yact,minn,Dir,d,xv,yv;
bool a[505][505];
int dist[505][505][8];
int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[]={0, 1, 1,  1,  0, -1,-1,-1};
int main ()
{
    f>>n>>m;
    f>>x>>y; f>>X>>Y;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            {f>>a[i][j]; a[i][j]=1-a[i][j];}

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            for (int o=0; o<8; ++o)
                dist[i][j][o]=inf;

    for (i=0; i<8; ++i)
    {E.x=x; E.y=y; E.dir=i; q.push(E); dist[x][y][i]=0;}

    while (! q.empty())
    {
        E=q.front(); q.pop();
        xv=E.x+dx[E.dir]; yv=E.y+dy[E.dir];
        xact=E.x; yact=E.y; d=E.dir; Dir=E.dir;
        if (a[xv][yv] && dist[xv][yv][d]>dist[xact][yact][d])
        {
            dist[xv][yv][d]=dist[xact][yact][d];
            E.x=xv; E.y=yv; E.dir=d;
            q.push(E);
        }
        d=(Dir+7)%8;
        if (dist[xact][yact][Dir]+1<dist[xact][yact][d])
        {
            dist[xact][yact][d]=dist[xact][yact][Dir]+1;
            E.x=xact; E.y=yact; E.dir=d;
            q.push(E);
        }
        d=(Dir+9)%8;
        if (dist[xact][yact][Dir]+1<dist[xact][yact][d])
        {
            dist[xact][yact][d]=dist[xact][yact][Dir]+1;
            E.x=xact; E.y=yact; E.dir=d;
            q.push(E);
        }
    }
    minn=inf;
    for (i=0; i<8; ++i)
        minn=min(minn, dist[X][Y][i]);
    if (minn==inf) g<<"-1\n";
        else g<<minn<<"\n";
    return 0;
}
