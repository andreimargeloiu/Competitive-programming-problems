# include <fstream>
# include <vector>
# include <queue>
# include <algorithm>
# define inf 999999999
# define N 1050
using namespace std;
ifstream f("patrol.in");
ofstream g("patrol.out");
vector <int> v[N];
vector <short> ap[N][125];
struct elem
{
    int nod, timp;
}E;
queue <elem> q;
int i,j,n,m,x,y,p,L,cmmmc,minn;
int P[N][125], cost[N][125], C[N];
int cmmdc (int a, int b)
{
    int R;
    while (b!=0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return a;
}
void citire ()
{
    int i,j,ant;
    f>>n>>m>>p;
    for (i=1; i<=n; ++i)
        f>>C[i];

    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (i=1; i<=p; ++i)
    {
        f>>L;
        cmmmc=cmmmc*2*(L-1)/cmmdc(cmmmc, 2*(L-1));
        for (j=1; j<=L; ++j)
        {
            f>>x;
            P[x][j]=1; P[x][j+2*(L-j)]=1;
            if (j>1) ap[ant][x].push_back(j), ap[x][ant].push_back(j+2*(L-j)+1);
            ant=x;
        }
    }
}
void init ()
{
    int i,j,k;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<cmmmc; ++j)
            cost[i][j]=inf;
}
void BF (int k, int timp)
{
    int i,j,urm,T;
    E.nod=k; E.timp=timp;
    cost[k][timp]=C[k]; q.push(E);
    while (! q.empty())
    {
        E=q.front(); q.pop();
        k=E.nod; timp=E.timp;

        if (k==n) minn=min(minn, cost[k][timp]);
        if (cost[k][timp]>=minn) continue;

        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i]; T=(timp+1)%cmmmc;
            if (cost[urm][T]>cost[k][timp]+C[urm])
                if (! P[urm][T] && (find(ap[urm][k].begin(), ap[urm][k].end(), T)==ap[urm][k].end()))
                {
                    cost[urm][T]=cost[k][timp]+C[urm];
                    E.nod=urm; E.timp=T;
                    q.push(E);
                }
        }
    }
}
int main ()
{
    cmmmc=1;
    citire (); cmmmc+=2;
    init ();

    minn=inf;
    BF (1, 1);

    g<<minn<<"\n";

    return 0;
}
