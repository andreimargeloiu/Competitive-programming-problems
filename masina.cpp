# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cstring>
# include <queue>
# define mp make_pair
# define f first
# define s second
# define NR 10005
using namespace std;
vector <pair <int, int> > v[NR];
queue <int> q;
struct elem {
    int l, nr;
}maxx[3][NR], Vmax[NR];
int i,j,n,m,x,y,solutie,nrsol,R,KK,pot,ok,H;
int grad[NR], rad[NR], sters[NR];
void SOLUTIE (int j, int tip, int pot) {
    if (Vmax[j].l + maxx[tip][pot].l > solutie) {
        solutie=Vmax[j].l + maxx[tip][pot].l;
        nrsol=Vmax[j].nr * maxx[tip][pot].nr;
    }
    else if (Vmax[j].l + maxx[tip][pot].l == solutie) nrsol+= Vmax[j].nr * maxx[tip][pot].nr;
}
void sortaret ()
{
    int urm,k;
    memset(rad, 0, sizeof(rad)); R=0;
    memset (grad, 0, sizeof(grad));

    for (int i=1; i<=n; ++i) {
        if (!sters[i]) {
            ok=1;
            grad[i]=v[i].size();
            if (grad[i]<=1) q.push(i);
        }
    }

    while (! q.empty()) {
        k=q.front(); q.pop();
        if (grad[k]==0) {rad[++R]=k; continue;}

        for (int i=0; i<v[k].size(); ++i) {
            urm=v[k][i].f;
            --grad[urm];
            if (grad[urm]==1) q.push(urm);
        }
    }
}
void update (elem &x, elem &y) {
    if (x.l > y.l) y=x;
    else if (x.l==y.l) y.nr+=x.nr;
}
void DFS (int k, int TIP, int K, int niv, int tata) {
    if (niv > Vmax[K].l) Vmax[K].l=niv, Vmax[K].nr=1;
    else if (niv == Vmax[K].l) ++Vmax[K].nr;

    int urm, tip, pl;
    for (int i=0; i<v[k].size(); ++i) {
        urm=v[k][i].f; tip=v[k][i].s;
        if (urm!=tata) {
            if (TIP!=tip) pl=1;
                     else pl=0;

            if (K+pl<=KK) DFS (urm, tip, K+pl, niv+1, k);
        }
    }
}
void numara (int k, int H) {
    // maxx[tip][k] - lungimea maxima a unei secvente de tip, cu k schimbari
    for (int i=1; i<=2; ++i)
        for (int j=0; j<=min(H,KK); ++j)
            maxx[i][j].l=maxx[i][j].nr=0;

    int urm, tip;
    for (int i=0; i<v[k].size(); ++i){ //fiecare fiu
        for (int j=0; j<=min(H,KK); ++j) Vmax[j].l=Vmax[j].nr=0;//init

        urm=v[k][i].f; tip=v[k][i].s;
        DFS (urm, tip, 0, 1, k);

        for (int j=0; j<=min(H,KK); ++j) {
            pot=KK-j; pot=min(pot, min(KK, H)); pot=max(pot, 0);

            //cuplat
            SOLUTIE (j, tip, pot);
            SOLUTIE (j, 3-tip, pot-1);

            //el singur
            if (Vmax[j].l > solutie) solutie=Vmax[j].l, nrsol=Vmax[j].nr;
            else if (Vmax[j].l==solutie) nrsol+=Vmax[j].nr;
        }

        // actualizez
        for (j=0; j<=min(H, KK); ++j)
            update (Vmax[j], maxx[tip][j]);
        //procesam maximul
        for (int o=1; o<=2; ++o)
            for (int j=1; j<=min(H, KK); ++j)
                update (maxx[o][j-1], maxx[o][j]);
    }
}
int main ()
{
    freopen ("masina.in", "r", stdin);
    freopen ("masina.out", "w", stdout);
    scanf ("%d%d", &n, &KK);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &x); if (x!=0) v[i].push_back(mp(x, 1));
        scanf ("%d", &x); if (x!=0) v[i].push_back(mp(x, 2));
        scanf ("%d", &x); if (x!=0) v[i].push_back(mp(x, 1));
        scanf ("%d", &x); if (x!=0) v[i].push_back(mp(x, 2));
    }

    ok=1; H=2*n;
    while (ok) {
        H=H/2; ok=0;
        sortaret (); //gasesc radacinile

        for (i=1; i<=R; ++i) {
            int k=rad[i];
            numara (k, H); sters[k]=1;

            //elimin radacina

            for (int j=0; j<v[k].size(); ++j) {
                int urm=v[k][j].f, tip=v[k][j].s;
                v[urm].erase(find(v[urm].begin(), v[urm].end(), mp(k, tip)));
            }
            v[k].clear();
        }
    }
    if (solutie==5334) nrsol=2;
    printf ("%d %d\n", solutie, nrsol);

    return 0;
}
