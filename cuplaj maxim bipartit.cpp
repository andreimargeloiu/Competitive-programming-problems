# include <bits/stdc++.h>
# define NR 10005
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
vector <int> v[NR];
int i,j,n,m,x,y,VV,sol,cuplate,E;
int M1[NR], M2[NR], ap[NR];
int cupleaza (int k) {
    if (ap[k]==VV) return 0;
    ap[k]=VV;
    for (auto &x: v[k]) {
        if (! M2[x]) {
            M1[k]=x;
            M2[x]=k;
            return 1;
        }
    }
    for (auto &x: v[k]) {
        if (cupleaza(M2[x])) {
            M1[k]=x;
            M2[x]=k;
            return 1;
        }
    }
    return 0;
}
int main ()
{
    f>>n>>m>>E;
    for (int i=1; i<=E; ++i) {
        f>>x>>y;
        v[x].push_back(y);
    }

    cuplate=1;
    while (cuplate) {
        cuplate=0; ++VV;
        for (int i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=cupleaza(i);
    }
    for (int i=1; i<=n; ++i)
        if (M1[i]) ++sol;

    g<<sol<<"\n";
    for (int i=1; i<=n; ++i)
        if (M1[i]) g<<i<<" "<<M1[i]<<"\n";


    return 0;
}
