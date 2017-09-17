# include <fstream>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 1005
# define inf 999999999
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
vector <int> v[NR];
queue <int> q;
int i,j,n,m,x,y,S,D,cap,flux;
int C[NR][NR], F[NR][NR], T[NR];
int BFS ()
{
    int ok=0, k, i;
    q.push(S);
    memset (T, 0, sizeof(T));
    T[S]=-1;
    while (! q.empty())
    {
        k=q.front(); q.pop();
        for (int i=0; i<v[k].size(); ++i)
            if (T[v[k][i]]==0 && C[k][v[k][i]]>F[k][v[k][i]])
            {
                if (v[k][i]==D) ok=1;
                else {
                         T[v[k][i]]=k;
                         q.push(v[k][i]);
                     }
            }
    }
    return ok;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i)
    {
        f>>x>>y>>cap;
        v[x].push_back(y); C[x][y]=cap;
        v[y].push_back(x);
    }

    S=1; D=n;

    while (BFS ())
    {
        for (int i=0; i<v[D].size(); ++i)
        {
            int ant=v[D][i];
            if (T[ant]!=0 && C[ant][D]>F[ant][D])
            {
                int minn=inf; T[D]=ant;
                for (int nod=D; nod!=S; nod=T[nod])
                    minn=min(minn, C[T[nod]][nod] - F[T[nod]][nod]);

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
    g<<flux<<"\n";

    return 0;
}

