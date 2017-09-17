# include <bits/stdc++.h>
using namespace std;
ifstream f("ro.in");
ofstream g("ro.out");
int
void DFS (int k, int nivel, int tata) {
    ap[k]=1; niv[k]=nivel; minn[k]=nivel;
    for (auto &x: v[k])
        if (x.y!=tata) {
            if (! ap[x.y]) {
                ++VV; st[VV].x=k; st[VV].y=x.y;
                DFS (x.y, nivel+1, k);

                if (minn[x.y] >= nivel) { // o noua componenta biconexa
                    critic[k]=1; ++nrCompBiconexe;

                    while (st[VV].x != k) {
                        comp[nrCompBiconexe].push_back(st[VV].y);
                        componenta[st[VV].y]=nrCompBiconexe;
                        --VV;
                    }
                    comp[nrCompBiconexe].push_back(st[VV].x);
                    comp[nrCompBiconexe].push_back(st[VV].y);
                    --VV;
                }
                   minn[k]=min(minn[k], minn[x.y]);
            } else minn[k]=min(minn[k], niv[x.y]);
        }
    if (critic[k]) Ncritice[++NC]=k;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>cost[i];

    for (i=1; i<=m; ++i) {
        f>>x>>y; E.i=i;
        E.y=y; v[x].push_back(E);
        E.y=x; v[y].push_back(E);
    }
    DFS (1, 0, 0);



    return 0;
}
