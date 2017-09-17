# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 1005
# define inf 999999999
using namespace std;
ifstream f("critice.in");
ofstream g("critice.out");
struct elem
{
    int x,y;
}muchie[11*NR];
vector <int> v[NR];
queue <int> q;
int i,j,n,m,flux,S,D,x,y,minn,VV;
int T[NR], c[NR][NR], F[NR][NR], sol[11*NR], ap1[NR], ap2[NR];
bool BFS ()
{
    int ok=0,i,k,urm;
    memset (T, 0, sizeof(T));
    T[S]=-1; q.push(S);

    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i];
            if (T[urm]==0 && c[k][urm]>F[k][urm])
            {
                if (urm==D) ok=1;
                else {
                         T[urm]=k;
                         q.push(urm);
                     }
            }
        }
    }
    return ok;
}
void dinic ()
{
    int i;
    while (BFS())
    {
        for (i=0; i<v[D].size(); ++i)
        {
            int ant=v[D][i];
            if (T[ant]!=0 && c[ant][D]>F[ant][D])
            {
                T[D]=ant; minn=inf;
                for (int nod=D; nod!=S; nod=T[nod])
                    minn=min(minn, c[T[nod]][nod] - F[T[nod]][nod]);

                if (minn<=0) continue;

                flux+=minn;

                for (int nod=D; nod!=S; nod=T[nod])
                {
                    F[T[nod]][nod]+=minn;
                    F[nod][T[nod]]-=minn;
                }
            }
        }
    }
}
void BFS1 (int S, int ap[])
{
    int i,k,urm;
    ap[S]=1; q.push(S);

    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i];
            if (F[k][urm]==c[k][urm] || F[k][urm]==-c[k][urm]) continue;
            else {
                    if (!ap[urm])
                    {
                        ap[urm]=1;
                        q.push(urm);
                    }
                 }
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y; f>>c[x][y]; c[y][x]=c[x][y];

        muchie[i].x=x; muchie[i].y=y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    S=1; D=n;

    dinic();

    BFS1(S, ap1);
    BFS1(D, ap2);

    for (i=1; i<=m; ++i)
        if ((ap1[muchie[i].x] && ap2[muchie[i].y]) || (ap1[muchie[i].y] && ap2[muchie[i].x])) sol[++VV]=i;


    //g<<FLUX<<"\n";

    g<<VV<<"\n";
    for (i=1; i<=VV; ++i)
        g<<sol[i]<<"\n";


    return 0;
}
