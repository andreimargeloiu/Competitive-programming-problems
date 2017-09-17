# include <bits/stdc++.h>
# define NR 500005
# define mp make_pair
# define f first
# define s second
# define INF 999999999
using namespace std;
ifstream f("evacuare.in");
ofstream g("evacuare.out");
vector <pair<int, int> > HEAP, v[NR];
bool cmp (pair <int, int> &x, pair <int, int> &y) {
    return x.f < y.f;
}
void baga (int cost, int k) {
    HEAP.push_back(mp(cost, k));
    push_heap(HEAP.begin(), HEAP.end(), cmp);
}
void scoate () {
    pop_heap(HEAP.begin(), HEAP.end(), cmp);
    HEAP.pop_back();
}

int i,j,n,m,x,y,X,k;
int minn[NR], ap[NR];

int main ()
{
    f>>n>>m>>X;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(mp(y, 1));
        v[y].push_back(mp(x, 1));
    }
    for (i=1; i<=n; ++i) {
        minn[i]=INF; f>>x;
        v[i].push_back(mp(x, 0));
    }

    baga(0, X); minn[X]=0;
    while (HEAP.size()) {
        k=HEAP[0].s; scoate();
        if (ap[k]) continue;
        ap[k]=1;

        for (auto &x: v[k]) {
            if (minn[k] + x.s < minn[x.f]) {
                minn[x.f]=minn[k] + x.s;
                baga(-minn[x.f], x.f);
            }
        }
    }
    for (i=1; i<=n; ++i)
        g<<minn[i]<<"\n";


    return 0;
}
