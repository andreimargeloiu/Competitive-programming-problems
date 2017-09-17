# include <bits/stdc++.h>
# define NR 200005
using namespace std;
ifstream f("kdist.in");
ofstream g("kdist.out");
vector <int> v[NR], store[NR];
struct elem {
    int x, t1, t2;
}aux[NR], E;
struct elem2 {
    int k, niv;
}RMQ[20][2*NR];

int i,j,n,m,x,y,K,Rt1,Rt2,VV,k,W,t1,t2;
int H[NR], R[NR], ap[NR], lg[2*NR], Col[NR], niv[NR], poz[NR];
long long sol;

void DFS (int k, int nivel) {
    ap[k]=1; niv[k]=nivel;

    ++VV; poz[k]=VV;
    RMQ[0][VV].k=k; RMQ[0][VV].niv=nivel;

    store[Col[k]].push_back(k);

    for (auto x: v[k]) {
        if (! ap[x]) {
            DFS (x, nivel+1);
            ++VV;  RMQ[0][VV].k=k; RMQ[0][VV].niv=nivel;
        }
    }
}
void logaritmi () {
    for (int i=2; i<=VV; ++i)
        lg[i]=lg[i/2] + 1;
}
void rmq () {
    for (int i=1; i<=lg[VV]; ++i)
        for (int j=1; j<=VV - (1<<(i-1))+1; ++j)
            if (RMQ[i-1][j].niv < RMQ[i-1][j+(1<<(i-1))].niv) RMQ[i][j]=RMQ[i-1][j];
                                                         else RMQ[i][j]=RMQ[i-1][j+(1<<(i-1))];
}
int lca (int X, int Y) {
    int ci, cs, LG;
    ci=poz[X]; cs=poz[Y]; if (ci > cs) swap(ci, cs);
    LG=lg[cs-ci+1];

    if (RMQ[LG][ci].niv < RMQ[LG][cs-(1<<LG)+1].niv) return RMQ[LG][ci].k;
                                                else return RMQ[LG][cs-(1<<LG)+1].k;
}
bool cmp (elem x, elem y) {
    return niv[x.x] > niv[y.x];
}
void initPadure () {
    for (int i=1; i<=n; ++i)
        R[i]=i, H[i]=1;
}
int radacina (int k) {
    while (R[k]!=k) k=R[k];
    return k;
}
void unite (int X, int Y) {
    if (H[X] > H[Y]) R[Y]=X, H[X]+=H[Y];
                else R[X]=Y, H[Y]+=H[X];
}
int main ()
{
    f>>n>>K;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        f>>Col[i];

    DFS (1, 1);

    logaritmi ();
    rmq();
    initPadure();
    for (k=1; k<=K; ++k) { //pentru fiecare culoare
        if (store[k].size()==1) {
            g<<"0\n";
            continue;
        }
        sol=0; W=0;
        for (auto x: store[k]) // inaltimile initiale
            sol=sol + 1LL*(store[k].size()-1)*niv[x];

        for (i=1; i<store[k].size(); ++i) { // fac lca-urile
            x=lca (store[k][i], store[k][i-1]);

            E.x=x; E.t1=store[k][i-1]; E.t2=store[k][i];
            aux[++W]=E;
        }
        sort (aux+1, aux+W+1, cmp);

        for (i=1; i<=W; ++i) {
            x=aux[i].x; t1=aux[i].t1; t2=aux[i].t2;

            Rt1=radacina(t1); Rt2=radacina(t2);
            sol=sol - 1LL * 2 * niv[x] * H[Rt1] * H[Rt2];

            unite (Rt1, Rt2);
        }
        g<<sol<<"\n";
    }

    return 0;
}
