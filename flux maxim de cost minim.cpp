# include <bits/stdc++.h>
# define NR 355
# define INF 999999999
using namespace std;
ifstream f("fmcm.in");
ofstream g("fmcm.out");
queue <int> q;
vector <int> v[NR];
int i,j,n,m,cost,cap,sol,minn,S,D,x,y;
int ap[NR], COST[NR][NR], c[NR], T[NR], F[NR][NR], C[NR][NR];

int BF () {
    for (int i=1; i<=n; ++i) T[i]=0, c[i]=INF, ap[i]=0;

    ap[S]=1; T[S]=-1; c[S]=0; q.push(S);
    while (! q.empty()) {
        int k=q.front(); q.pop();
        ap[k]=0;

        for (auto &x: v[k]) {
            if (C[k][x] > F[k][x] && c[k] + COST[k][x] < c[x]) {
                c[x]=c[k] + COST[k][x];
                T[x]=k;

                if (! ap[x]) {
                    ap[x]=1;
                    q.push(x);
                }
            }
        }
    }
    if (T[D]) return 1;
         else return 0;
}
int main ()
{
    f>>n>>m>>S>>D;

    for (i=1; i<=m; ++i) {
        f>>x>>y>>cap>>cost;

        v[x].push_back(y);
        v[y].push_back(x);
        C[x][y]=cap;
        COST[x][y]=cost; COST[y][x]-=cost;
    }
    while (BF ()) {
        int minn=INF;
        for (int nod=D; nod!=S; nod=T[nod])
            minn=min(minn, C[T[nod]][nod] - F[T[nod]][nod]);

        for (int nod=D; nod!=S; nod=T[nod]) {
            F[T[nod]][nod]+=minn;
            F[nod][T[nod]]-=minn;
        }
        sol=sol + minn * c[D];
    }
    g<<sol<<"\n";

    return 0;
}
