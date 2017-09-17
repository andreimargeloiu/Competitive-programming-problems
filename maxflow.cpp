# include <bits/stdc++.h>
# define NR 1005
# define INF 999999999
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
vector <int> v[NR];
queue <int> q;
int i,j,n,m,flux,minn,x,y,cap;
int T[NR], C[NR][NR], F[NR][NR];
int BFS () {
    int ok=0;
    for (int i=1; i<=n; ++i) T[i]=0;
    T[1]=-1; q.push(1);
    while (! q.empty()) {
        int k=q.front(); q.pop();
        for (auto &x: v[k]) {
            if (T[x]==0 && C[k][x] > F[k][x]) {
                if (x==n) ok=1;
                else {
                    T[x]=k;
                    q.push(x);
                }
            }
        }
    }
    return ok;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y>>cap;
        v[x].push_back(y);
        v[y].push_back(x);
        C[x][y]+=cap;
    }

    while (BFS()) {
        for (auto &x: v[n])
            if (T[x] && C[x][n] > F[x][n]) {
                minn=INF; T[n]=x;
                for (int nod=n; nod!=1; nod=T[nod])
                    minn=min(minn, C[T[nod]][nod] - F[T[nod]][nod]);

                if (minn<=0) continue;
                flux+=minn;

                for (int nod=n; nod!=1; nod=T[nod]) {
                    F[T[nod]][nod]+=minn;
                    F[nod][T[nod]]-=minn;
                }
            }
    }
    g<<flux<<"\n";

    return 0;
}
