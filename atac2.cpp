# include <cstdio>
# include <algorithm>
# include <vector>
# include <queue>
# include <cstring>
# define NR 10005
# define NR2 205
# define inf 999999999
# define mp make_pair
using namespace std;
vector <int> v[NR], F[NR2];
vector <pair <int, int> > HEAP;
queue <int> q;
int i,j,n,m,x,y,S,D,VV,U,X,nod,sol,nrV;
int flux[NR2][NR2], cap[NR2][NR2], dist[NR], T[NR2], oras[NR2], cost[NR2][NR2];
void Djikstra (int K) {
    int i,cact,k,urm;
    for (i=1; i<=n; ++i) dist[i]=inf;
    dist[K]=0;

    HEAP.push_back(mp(0, K));
    push_heap (HEAP.begin(), HEAP.end());

    while (HEAP.size()) {
        cact=-HEAP[0].first; k=HEAP[0].second;
        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        if (cact > dist[k]) continue;

        for (int i=0; i<v[k].size(); ++i) {
            urm=v[k][i];

            if (dist[urm] > dist[k] + 1) {
                dist[urm]=dist[k]+1;

                HEAP.push_back(mp(-dist[urm], urm));
                push_heap(HEAP.begin(), HEAP.end());
            }
        }
    }
}
bool BFS () {
    int i,k,urm;
    for (i=1; i<=200; ++i)
        T[i]=-1, dist[i]=inf;

    q.push(S); dist[S]=0;
    while (! q.empty()) {
        k=q.front(); q.pop();
        for (i=0; i<F[k].size(); ++i) {
            urm=F[k][i];

            if (cap[k][urm]>flux[k][urm] && dist[urm]>dist[k]+cost[k][urm]) {
                dist[urm]=dist[k] + cost[k][urm];
                T[urm]=k;
                q.push(urm);
            }
        }
    }
    if (T[D]==-1) return 0;
             else return 1;
}
int main ()
{
    freopen ("atac2.in", "r", stdin);
    freopen ("atac2.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &U, &X);
    for (i=1; i<=U; ++i)
        scanf ("%d", &oras[i]);

    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    S=0; D=200;
    for (i=0; i<v[X].size(); ++i) {
        Djikstra (v[X][i]); nrV=U+i+1;

        cap[nrV][D]=1;
        F[nrV].push_back(D);
        F[D].push_back(nrV);

        for (j=1; j<=U; ++j) {
            cap[j][nrV]=1;
            F[j].push_back(nrV);
            F[nrV].push_back(j);

            cost[j][nrV]=dist[oras[j]];
            cost[nrV][j]=-dist[oras[j]];
        }
    }
    // S -> U
    for (i=1; i<=U; ++i) {
        cap[S][i]=1;
        F[S].push_back(i);
        F[i].push_back(S);
        /*for (j=1; j<=U+v[X].size(); ++j)
            printf ("%d ", cost[i][j]);
        printf ("\n");*/
    }
    memset (dist, 0, sizeof(dist));
    // facem cuplajul maxim de cost minim
    while (BFS ()) {
        for (nod=D; nod!=S; nod=T[nod]) {
            flux[T[nod]][nod]++;
            flux[nod][T[nod]]--;
        }
        sol+=dist[D];
    }
    printf ("%d\n", sol);


    return 0;
}
