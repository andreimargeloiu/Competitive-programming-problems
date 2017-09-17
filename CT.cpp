# include <fstream>
# include <algorithm>
# include <cstring>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("ct.in");
ofstream g("ct.out");
vector <int> v[NR];
int i,j,n,m,x,y,sol,K,teste;
int stiva[NR], niv[NR], T[NR][20], marcat[NR], lg[NR];
struct elem {
    int x, y, lca;
}Q[NR];
bool cmp (elem x, elem y) {
    return niv[x.lca] > niv[y.lca];
}
void logaritmi () {
    for (int i=2; i<=100000; ++i)
        lg[i]=lg[i/2] + 1;
}
void DFS (int k, int tata, int nivel) {
    niv[k]=nivel; stiva[nivel]=k;
    //facem vecinii lui de la 2^i numvele in sus
    for (int i=0; i<=lg[n] && (1<<i) < nivel; ++i)
        T[k][i]=stiva[nivel - (1<<i)];

    for (int i=0; i<v[k].size(); ++i)
        if (v[k][i]!=tata) DFS (v[k][i], k, nivel+1);
}
int LCA (int X, int Y) {
    if (niv[Y] > niv[X]) swap(X, Y);
    // le aduc pe acelasi nivel
    for (int j=lg[n]; j>=0 && niv[X]!=niv[Y]; --j)
        if (niv[X] - (1<<j) >= niv[Y]) X=T[X][j];

    if (X==Y) return X;
    // urc simultan cu ele
    for (int j=lg[n]; j>=0; --j)
        if (T[X][j] != T[Y][j]) X=T[X][j], Y=T[Y][j];

    return T[X][0];
}
void marcheaza (int k) {
    marcat[k]=1;
    for (int i=0; i<v[k].size(); ++i)
        if (! marcat[v[k][i]] && v[k][i]!=T[k][0])
            marcheaza (v[k][i]);
}
void init () {
    for (int i=1; i<=n; ++i) {
        v[i].clear ();
        marcat[i]=0; niv[i]=0;
        for (int j=0; j<=lg[n]; ++j)
            T[i][j]=0;
    }
}
int main ()
{
    logaritmi (); f>>teste;
    for (int t=1; t<=teste; ++t) {
        f>>n>>K; init ();

        for (i=1; i<n; ++i) {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        DFS (1, 0, 1);

        for (i=1; i<=K; ++i) {
            f>>Q[i].x>>Q[i].y;
            Q[i].lca=LCA (Q[i].x, Q[i].y);
        }

        sort (Q+1, Q+K+1, cmp);
        sol=0;
        for (i=1; i<=K; ++i)
            if (! marcat[Q[i].x] && ! marcat[Q[i].y]) { // un nou punct
                ++sol;
                marcheaza (Q[i].lca);
            }

        g<<sol<<"\n";
    }

    return 0;
}
