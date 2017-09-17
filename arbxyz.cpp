# include <bits/stdc++.h>
# define NR 100005
using namespace std;
ifstream f("arbxyz.in");
ofstream g("arbxyz.out");
vector <int> v[NR];
int x,y,n,K,K2,ok1,ok2,X,Y,Z,T,i,N,caut,OK,I1=0,I2=0;
int fii[NR];
void init () {
    for (int i=1; i<=n; ++i)
        v[i].clear();
}
bool interzis (int x, int y) {
    if ((x==I1 && y==I2) || (x==I2 && y==I1)) return 1;
                                         else return 0;
}
void DFS (int k, int tata, int &caut, int &ok) { //impart in X,  Y+Z
    if (ok) return; fii[k]=1;

    for (int i=0; i<v[k].size() && !ok; ++i)
        if (v[k][i]!=tata) {
            if (interzis (k, v[k][i])) continue;
            DFS (v[k][i], k, caut, ok);
            fii[k]+=fii[v[k][i]];
        }

    if (! ok && interzis (k, tata)==0) {
        if (fii[k] == caut) { //tai muchia
            K2=tata; ok=1;
            I1=k; I2=tata;
        } else if (N-fii[k] == caut) {
            K2=k; ok=1;
            I1=k; I2=tata;
        }
    }
}
int verifica (int X, int Y, int Z) {
    K2=0; ok1=0; ok2=0; N=n; I1=-1; I2=-1;

    memset (fii, 0, sizeof(fii));
    DFS (1, 0, X, ok1);

    if (ok1) {
        N=n-X; memset (fii, 0, sizeof(fii));
        DFS (K2, 0, Y, ok2);
    }

    if (ok1 && ok2) return 1;
               else return 0;
}
int main ()
{
    f>>T;
    while (T--) {
        f>>n>>X>>Y>>Z; init ();
        for (i=1; i<n; ++i) {
            f>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        OK=0;

        if (! OK) OK=verifica (X, Y, Z);
        if (! OK) OK=verifica (X, Z, Y);
        if (! OK) OK=verifica (Y, X, Z);
        if (! OK) OK=verifica (Y, Z, X);
        if (! OK) OK=verifica (Z, X, Y);
        if (! OK) OK=verifica (Z, Y, X);

        g<<OK<<"\n";
    }

    return 0;
}
