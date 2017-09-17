# include <bits/stdc++.h>
# define INF 999999999
# define NR 40
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("gard4.in");
ofstream g("gard4.out");
struct elem {
    int x, y, K, cost;
}E;
vector <elem> HEAP;
vector <pair <int, int> > col[NR];
struct cmp {
    bool operator () (const elem &x, const elem &y) {
        return x.cost > y.cost;
    }
};

int i,j,n,m,x,y,minn,DR,K,I,J;
int a[NR][NR], cost[NR][NR][1<<5];
int dx[]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[]={0, 1, 1, 1, 0, -1, -1, -1};
int schimb[]={-5, 1, 1, 1, -5, 0, 0, 0};

void bordare () {
    for (int i=0; i<=n+1; ++i)
        a[0][i]=a[n+1][i]=a[i][0]=a[i][n+1]=-1;
}
void init () {
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            for (int k=0; k<=(1<<K)-1; ++k)
                cost[i][j][k]=INF;
}
void baga (int x, int y, int K, int cost) {
    elem E;
    E.x=x; E.y=y; E.K=K; E.cost=cost;
    HEAP.push_back(E);
    push_heap(HEAP.begin(), HEAP.end(), cmp());
}
void scoate () {
    pop_heap(HEAP.begin(), HEAP.end(), cmp());
    HEAP.pop_back();
}
int make_bits (int J, int H) {
    int X=0;
    for (auto &x: col[J]) {
        if (x.f > H) {
            X+=(1<<x.s);
        }
    }

    return X;
}
void djikstra () {
    int x, y, K, cact, Kurm, lv, cv, X;
    while (HEAP.size()) {
        E=HEAP[0]; scoate();
        x=E.x; y=E.y; K=E.K; cact=E.cost;
        if (cact != cost[x][y][K]) continue;

        for (int i=0; i<8; ++i) {
            lv=x + dx[i]; cv=y + dy[i];
            if (a[lv][cv]!=-1) {//daca pot pasi aici
                if (schimb[i]!=-5) {
                    if (schimb[i]==1) X=make_bits(y + schimb[i], lv);
                                 else X=make_bits(y, x);
                }
                else X=0;

                Kurm=K xor X;
                if (cost[lv][cv][Kurm] > cost[x][y][K] + a[lv][cv]) {
                    cost[lv][cv][Kurm]=cost[x][y][K] + a[lv][cv];

                    baga(lv, cv, Kurm, cost[lv][cv][Kurm]);
                }
            }
        }

    }
}
int main ()
{
    f>>n; DR=INF; bordare();
    for (i=1; i<=n; ++i) {
        for (j=1; j<=n; ++j) {
            f>>a[i][j];
            if (a[i][j]==-1) {//un nou punct
                col[j].push_back(mp(i, K));
                ++K;
                if (j<DR) {
                    DR=j;
                    I=i; J=j;
                }
            }
        }
    }
    minn=INF;
    for (i=1; i<=J; ++i) {
        init ();
        baga(I, i, 0, 0);
        cost[I][i][0]=0;
        djikstra ();

        if (cost[I][i][(1<<K) - 1] < minn)
            minn=cost[I][i][(1<<K) - 1];
    }
    g<<minn<<"\n";

    return 0;
}
