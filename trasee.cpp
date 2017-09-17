# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <queue>
# define NR 205
# define inf 999999999
# define mp make_pair
using namespace std;
vector <int> v[NR], v2[NR];
queue <int> q;
int i,j,n,m,x,y,S,L,nrsol,ok,k,R,minn,flux;
int dist[NR], C[NR][NR], F[NR][NR], T[NR];
void BF (int k)
{
    int i,urm;
    dist[k]=1; q.push(k);
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            urm=v[k][i];
            if (! dist[urm] || dist[k]+1<dist[urm])
            {
                dist[urm]=dist[k]+1;
                q.push(urm);
            }
        }
    }
}
bool BFS ()
{
    int i, ok=0;
    memset (T, 0, sizeof(T));
    q.push(S); T[S]=-1;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (i=0; i<v2[k].size(); ++i)
        {
            int urm=v2[k][i];
            if (T[urm]==0 && C[k][urm]>F[k][urm])
            {
                if (urm==R) ok=1;
                else {
                         T[urm]=k;
                         q.push(urm);
                     }
            }
        }
    }

    return ok;
}
int main ()
{
    freopen ("trasee.in", "r", stdin);
    freopen ("trasee.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &S, &L);
    for (i=1; i<=m; ++i)
    {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BF (S); R=n+1;
    for (i=1; i<=n; ++i)
    {
        for (j=0; j<v[i].size(); ++j)
            if (dist[v[i][j]]==dist[i]+1)
            {
                v2[i].push_back(v[i][j]);
                v2[v[i][j]].push_back(i);

                C[i][v[i][j]]=1; C[v[i][j]][i]=0;
            }
        if (dist[i]==L)
        {
            v2[R].push_back(i);
            v2[i].push_back(R);

            C[i][R]=inf; C[R][i]=0;
        }
    }

    while (BFS ())
    {
        for (i=0; i<v2[R].size(); ++i)
        {
            int ant=v2[R][i];
            if (T[ant]!=0 && C[ant][R]>F[ant][R])
            {
                T[R]=ant; minn=inf;
                for (int nod=R; nod!=S; nod=T[nod])
                    minn=min(minn, C[T[nod]][nod]-F[T[nod]][nod]);

                if (minn<=0) continue;
                flux+=minn;

                for (int nod=R; nod!=S; nod=T[nod])
                {
                    F[T[nod]][nod]+=minn;
                    F[nod][T[nod]]-=minn;
                }
            }
        }
    }

    printf ("%d\n", flux);
    return 0;
}
