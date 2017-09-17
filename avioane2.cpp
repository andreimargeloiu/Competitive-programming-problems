# include <bits/stdc++.h>
# define NR 200005
using namespace std;
ifstream f("avioane2.in");
ofstream g("avioane2.out");
struct elem {
    int a, timp, tip, b, tb;
    long long cost;
}E;
// tip 1 -> aterizare
// tip 2 -> decolae
// tip 3 -> query
vector <elem> HEAP;
struct cmp {
    bool operator() (const elem &x, const elem &y) {
        if (x.timp != y.timp) return x.timp > y.timp;
                         else return x.tip > y.tip;
    }
};
void baga (elem E) {
    HEAP.push_back(E);
    push_heap(HEAP.begin(), HEAP.end(), cmp());
}
void scoate () {
    pop_heap(HEAP.begin(), HEAP.end(), cmp());
    HEAP.pop_back();
}
int i,j,n,m,x,y,Q;
long long INF=1e16, sol[NR], minn[NR];
void djikstra () {
    elem K;
    while (HEAP.size()) {
        K=HEAP[0]; scoate();
        if (K.tip==1) { //aterizare
            if (K.cost < minn[K.a]) minn[K.a]=K.cost;
        } else if (K.tip==2) { //decolare
            if (minn[K.a] + K.cost < minn[K.b]) {
                E.a=K.b; E.timp=K.tb; E.cost=minn[K.a] + K.cost; E.tip=1; E.b=0;
                baga(E);
            }
        } else {
            sol[K.b]=minn[K.a];
        }
    }
}
int main ()
{
    f>>n>>m>>Q;
    for (i=1; i<=m; ++i) {
        f>>E.a>>E.timp>>E.b>>E.tb>>E.cost; E.tip=2;

        baga(E);
    }
    for (i=1; i<=Q; ++i) {
        f>>E.a>>E.timp; E.tip=3; E.b=i; E.tb=0; E.cost=0;
        baga(E);
    }
    for (i=2; i<=n; ++i)
        minn[i]=INF;
    djikstra ();

    for (i=1; i<=Q; ++i)
        if (sol[i]==INF) g<<"-1\n";
                    else g<<sol[i]<<"\n";

    return 0;
}
