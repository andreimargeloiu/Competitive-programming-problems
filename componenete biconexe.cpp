# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
vector <int> v[NR], sol[NR];
struct elem {
    int x, y;
}st[NR];

int i,j,n,m,nrsol,VV,x,y;
int T[NR], ap[NR], niv[NR], minn[NR];

void DFS (int k, int nivel, int tata) {
    ap[k]=1; niv[k]=nivel; minn[k]=nivel; T[k]=tata;
    for (auto &x: v[k]) {
        if (x!=tata) {
            if (! ap[x]) {
                ++VV; st[VV].x=k; st[VV].y=x;

                DFS (x, nivel+1, k);

                if (minn[x]>=nivel) { // e punct de articulatie si fac componenta biconexa
                    ++nrsol;
                    while (st[VV].x!=k) {
                        sol[nrsol].push_back(st[VV].y);
                        --VV;
                    }
                    sol[nrsol].push_back(st[VV].x);
                    sol[nrsol].push_back(st[VV].y);
                    --VV;
                }
                minn[k]=min(minn[k], minn[x]);
            } else minn[k]=min(minn[k], niv[x]);
        }
    }
}
int main ()
{
    f>>n>>m;
    for (int i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1, 1, 0);

    g<<nrsol<<"\n";
    for (int i=1; i<=nrsol; ++i) {
        for (auto &x: sol[i])
            g<<x<<" ";
        g<<"\n";
    }

    return 0;
}
