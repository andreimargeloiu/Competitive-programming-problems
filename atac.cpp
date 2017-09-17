# include <bits/stdc++.h>
# define NR 35000
# define mp make_pair
# define f first
# define s second
# define INF 999999999
# define DIM 17
using namespace std;
ifstream f("atac.in");
ofstream g("atac.out");
vector <pair <int, int> > v[NR];
int i,j,n,m,A,B,C,D,X,Y,Z,niv[NR],Q,P,x,cost;
int best[DIM][NR], T[DIM][NR];

void DFS (int k, int nivel) {
    niv[k]=nivel;

    for (int i=1; (1<<i)<=nivel; ++i) {
        T[i][k]=T[i-1][T[i-1][k]];
        best[i][k]=min(best[i-1][k], best[i-1][T[i-1][k]]);
    }

    for (auto &x: v[k]) { //daca nu am mai trecut pe aici
        DFS (x.f, nivel+1);
    }
}
int query (int X, int Y) {
    int minim=INF;
    if (X==Y) return 0;

    if (niv[X] < niv[Y]) swap(X, Y);
    for (int i=DIM-1; i>=0; --i)
        if (niv[X] - (1<<i)>=niv[Y]) {
            minim=min(minim, best[i][X]);
            X=T[i][X];
        }

    for (int i=DIM-1; i>=0; --i) {
        if (T[i][X]!=T[i][Y]) {
            minim=min(minim, best[i][X]);
            minim=min(minim, best[i][Y]);

            X=T[i][X];
            Y=T[i][Y];
        }
    }
    if (X!=Y) {
        minim=min(minim, min(best[0][X], best[0][Y]));
    }

    return minim;
}
int main ()
{
    f>>n>>Q>>P;

    for (i=2; i<=n; ++i) {
        f>>x>>cost;
        T[0][i]=x; best[0][i]=cost;
        v[x].push_back(mp(i, cost));
    }
    best[0][1]=INF; DFS (1, 0);

    f>>X>>Y>>A>>B>>C>>D;
    for (i=1; i<=Q; ++i) {
        Z=query (X, Y);
        if (i>=Q - P + 1) g<<Z<<"\n";

        X=(X*A + Y*B)%n + 1;
        Y=(Y*C + Z*D)%n + 1;
    }

    return 0;
}
