# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# include <queue>
# include <bitset>
# define NR 505
# define inf 999999
using namespace std;
ifstream f("joc4.in");
ofstream g("joc4.out");
vector <short> v[NR];
queue <short> Q;
int i,j,n,m,x,y,S,D,nod,flux,minn;
short T[NR], F[NR][NR];
bitset <NR> c[NR];
bool bfs ()
{
    int i, ok=0;
    memset (T, 0, sizeof(T));
    Q.push(S); T[S]=-1;
    while (! Q.empty())
    {
        int k=Q.front(); Q.pop();
        for (i=0; i<v[k].size(); ++i)
        {
            int urm=v[k][i];
            if (! T[urm] && c[k][urm]>F[k][urm])
            {
                if (urm==D) ok=1;
                else {
                         T[urm]=k;
                         Q.push(urm);
                     }
            }
        }
    }
    return ok;
}
int main ()
{
    f>>n>>m>>S>>D; S=2*S+1; D=2*D;

    // 2*x   - intrare
    // 2*x+1 - iesire

    //din iesirea primului in intrarea la al doilea
    //din iesirea la al doilea in intrare la primul

    for (i=1; i<=m; ++i)
    {
        f>>x>>y;
        v[2*x+1].push_back(2*y); c[2*x+1][2*y]=1;
        v[2*y].push_back(2*x+1);

        v[2*y+1].push_back(2*x); c[2*y+1][2*x]=1;
        v[2*x].push_back(2*y+1);
    }

    for (i=1; i<=n; ++i)
    {
        v[2*i].push_back(2*i+1); c[2*i][2*i+1]=1;
        v[2*i+1].push_back(2*i);
    }

    //dinic
    while (bfs())
    {
        for (i=0; i<v[D].size(); ++i)
        {
            int urm=v[D][i];
            if (T[urm] && c[urm][D]>F[urm][D])
            {
                T[D]=urm; minn=inf;
                for (nod=D; nod!=S; nod=T[nod])
                    minn=min(minn, c[T[nod]][nod]-F[T[nod]][nod]);

                if (minn<=0) continue;

                flux+=minn;

                for (nod=D; nod!=S; nod=T[nod])
                {
                    F[T[nod]][nod]+=minn;
                    F[nod][T[nod]]-=minn;
                }
            }
        }
    }
    g<<flux<<"\n";

    return 0;
}
