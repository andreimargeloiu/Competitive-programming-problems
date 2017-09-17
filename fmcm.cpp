# include <fstream>
# include <vector>
# include <algorithm>
# include <queue>
# include <cstring>
# define NR 355
# define INF 999999999
using namespace std;
ifstream f("fmcm.in");
ofstream g("fmcm.out");
vector <int> v[NR];
queue <int> q;
int i,j,n,m,x,y,cap,cost,minn,S,D,sol,nod;
int Cap[NR][NR], Cost[NR][NR], T[NR], C[NR], ap[NR], flux[NR][NR];
bool BF () {
    int i,k,urm,cost;
    for (i=1; i<=n; ++i) C[i]=INF, ap[i]=0, T[i]=0;

    C[S]=0; q.push(S);
    while (! q.empty()) {
        k=q.front(); q.pop();
        ap[k]=0;

        for (i=0; i<v[k].size(); ++i) {
            urm=v[k][i]; cost=Cost[k][urm];

            if (Cap[k][urm] > flux[k][urm] && C[urm] > C[k] + cost) {
                C[urm] = C[k] + cost;
                T[urm]=k;
                if (! ap[urm]) {
                    ap[urm]=1;
                    q.push (urm);
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

        v[x].push_back(y); v[y].push_back(x);
        Cap[x][y]=cap;
        Cost[x][y]=cost;   Cost[y][x]=-cost;
    }

    while (BF()) {
        minn=INF;
        for (nod=D; nod!=S; nod=T[nod])
            minn=min(minn, Cap[T[nod]][nod] - flux[T[nod]][nod]);

        for (nod=D; nod!=S; nod=T[nod]) {
            flux[T[nod]][nod]+=minn;
            flux[nod][T[nod]]-=minn;
        }
        sol+=C[D]*minn;
    }
    g<<sol<<"\n";


    return 0;
}
