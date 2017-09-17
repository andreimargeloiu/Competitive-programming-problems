# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
struct elem {
    int x, y;
}st[NR];
vector <int> v[NR], sol[NR];
int i,j,n,m,VV,nrsol,x,y;
int ap[NR], niv[NR], minn[NR];
void DFS (int k, int nivel, int tata) {
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;

    for (auto &x: v[k]) {
        if (x==tata) continue;
        else {
            if (! ap[x]) { //fiu
                ++VV; st[VV].x=k; st[VV].y=x;

                DFS (x, nivel+1, k);

                if (minn[x] >= nivel) { // punct de articulatie
                    ++nrsol;

                    while (st[VV].x != k) {
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
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i, 1, 0);

    g<<nrsol<<"\n";
    for (i=1; i<=nrsol; ++i) {
        for (auto &x: sol[i])
            g<<x<<" ";
        g<<"\n";
    }

    return 0;
}
