# include <cstdio>
# include <algorithm>
# include <cstring>
# include <vector>
# include <queue>
# include <set>
# define NR 150005
using namespace std;
queue <int> q;
vector <int> v[NR], vt[NR], comp[NR], tare[NR];

struct elem {
    int dist, nod;
}E;
struct cmp {
    bool operator () (const elem &x, const elem &y) {
        if (x.dist <= y.dist) return 0;
                        else return 1;
    }
};
multiset <elem, cmp> M;

int i,j,n,m,x,y,VV,TC,nod,o,urm,Q,F,S;
int in[NR], num[NR], ap[NR], ant[NR], Tconex[NR], sol[NR], dist[NR];

int mat[100][100];

void DFS (int k) {
    ap[k]=1;
    for (int i=0; i<v[k].size(); ++i) {
        if (! ap[v[k][i]]) DFS (v[k][i]);
    }
    ant[++VV]=k;
}
void DFSt (int k) {
    ap[k]=0; Tconex[k]=TC;
    comp[TC].push_back(k);
    for (int i=0; i<vt[k].size(); ++i)
        if (ap[vt[k][i]]==1) DFSt (vt[k][i]);
}
void DF (int k) {
    int urm; ap[k]=1;
    for (int i=0; i<tare[k].size(); ++i) {
        urm=tare[k][i];
        if (! ap[urm]) DF (urm);
        dist[k]=max(dist[k], 1+dist[urm]);
    }
}
void sortaret () {
    int i,j,nod, VV=0;
    for (i=1; i<=TC; ++i)
        if (in[i]==0) {
            E.dist=dist[i];
            E.nod=i; ++VV;
            M.insert (E);
        }

    while (M.size()) {
        if (M.size()==1) { // e solutie
            num[(*M.begin()).nod]=1;
        }

        VV=(*M.begin()).dist;
        while (M.size() && (*M.begin()).dist==VV) {
            E=*M.begin(); M.erase(M.find(E));

            nod=E.nod;
            for (i=0; i<tare[nod].size(); ++i) {
                urm=tare[nod][i];
                --in[urm];
                if (in[urm]==0) {
                    E.nod=urm; E.dist=dist[urm];
                    M.insert (E); ++VV;
                }
            }
        }
    }
}
int main ()
{
    freopen ("drumuri5.in", "r", stdin);
    freopen ("drumuri5.out", "w", stdout);

    scanf ("%d%d", &n, &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d", &x, &y);
        v[x].push_back(y);
        vt[y].push_back(x);
    }
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);

    for (i=n; i>=1; --i)
        if (ap[ant[i]]==1) {//inca nu l-am parcurs pe G transpus
            ++TC;
            DFSt(ant[i]);
        }

    memset (ap, 0, sizeof(ap));
    // vectorul componentelor tare conexe
    for (i=1; i<=TC; ++i) {
        ap[i]=i;
        for (j=0; j<comp[i].size(); ++j) {
            nod=comp[i][j];

            for (o=0; o<v[nod].size(); ++o) { //verific vecinii
                urm=v[nod][o];
                if (ap[Tconex[urm]]!=i) {//daca e intr-o componenta tare conexa nevizitate
                    ap[Tconex[urm]]=i;

                    ++in[Tconex[urm]];
                    tare[i].push_back(Tconex[urm]);
                }
            }
        }
    }
    // fac distanta maxima a unui lant care intepe din TC i
    memset (ap, 0, sizeof(ap));
    for (i=1; i<=TC; ++i)
        if (!ap[i]) DF (i);
    //sortaret pe graful normal
    sortaret ();

    VV=0;
    for (i=1; i<=TC; ++i) {
        if (num[i]) { //cele de aici sunt solutie
            for (j=0; j<comp[i].size(); ++j)
                sol[++VV]=comp[i][j];
        }
    }
    sort (sol+1, sol+VV+1);
    printf ("%d\n", VV);
    for (i=1; i<=VV; ++i)
        printf ("%d ", sol[i]);
    printf ("\n");

    return 0;
}
