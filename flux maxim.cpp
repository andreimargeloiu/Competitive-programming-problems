# include <bits/stdc++.h>
# define NR 1005
# define INF 999999999
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
vector <int> v[NR];
queue <int> q;
int i,j,n,m,FLUX,minn,ant,x,S,D,y,cap,nod;
int T[NR], F[NR][NR], C[NR][NR];
bool BFS () {
    int OK=0, k;
    q.push(S);
    memset (T, 0, sizeof(T)); T[S]=-1;
    while (! q.empty()) {
        k=q.front(); q.pop();

        for (auto &x: v[k]) {
            if (T[x]==0 && F[k][x] < C[k][x]) {
                if (x==D) OK=1;
                else {
                    T[x]=k;
                    q.push(x);
                }
            }
        }
    }
    return OK;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y>>cap;

        v[x].push_back(y);
        v[y].push_back(x);

        C[x][y]=cap;
    }
    S=1; D=n;
    while (BFS ()) {
        for (auto &x: v[D]) {
            minn=INF;
            if (T[x] && F[x][D] < C[x][D]) {
                T[D]=x;
                for (nod=D; nod!=S; nod=T[nod])
                    minn=min(minn, C[T[nod]][nod] - F[T[nod]][nod]);

                if (minn<=0) continue;
                FLUX+=minn;

                for (nod=D; nod!=S; nod=T[nod]) {
                    F[T[nod]][nod]+=minn;
                    F[nod][T[nod]]-=minn;
                }
            }
        }
    }
    g<<FLUX<<"\n";

    return 0;
}
