# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 755
using namespace std;
vector <pair <int, pair<int, int> > > hp;
int i,j,n,m,hact,xact,yact,xv,yv,lv,cv;
int a[NR][NR];
long long sol;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool ap[NR][NR];
void adauga (int x, int y, int h)
{
    if (x<1 || x>n || y<1 || y>m) return;
    if (ap[x][y]) return;

    //adaug la solutie
    if (h<a[x][y]) h=a[x][y];
    sol=sol+h-a[x][y];

    //adag la heap
    hp.push_back(make_pair(-h, make_pair(x,y)));
    push_heap (hp.begin(), hp.end());
    ap[x][y]=1;
}
int main ()
{
    freopen ("volum.in", "r", stdin);
    freopen ("volum.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            scanf ("%d", &a[i][j]);

    for (i=1; i<=n; ++i)
    {
        adauga (i, 1, a[i][1]);
        adauga (i, m, a[i][m]);
    }

    for (j=1; j<=m; ++j)
    {
        adauga (1, j, a[1][j]);
        adauga (n, j, a[n][j]);
    }

    while (hp.size())
    {
        hact=-hp[0].first;
        xact=hp[0].second.first;
        yact=hp[0].second.second;

        pop_heap(hp.begin(), hp.end());
        hp.pop_back();
        for (i=0; i<4; ++i)
        {
            xv=xact+dx[i]; yv=yact+dy[i];
            adauga (xv, yv, hact);
        }
    }
    printf ("%lld", sol);

    return 0;
}
