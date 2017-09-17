# include <bits/stdc++.h>
# define NR 10005
using namespace std;
ifstream f("felinare.in");
ofstream g("felinare.out");
vector <int> v[NR];
int i,j,n,m,x,y,sol,cuplate,G;
int M1[NR], M2[NR], ap[NR], SR[NR], SL[NR];

int cupleaza (int k) {
    if (ap[k]==G) return 0;
    ap[k]=G;

    for (auto &x: v[k])
        if (! M2[x]) {
            M1[k]=x; M2[x]=k;
            SL[k]=1;
            return 1;
        }
    for (auto &x: v[k])
        if (cupleaza (M2[x])) {
            M1[k]=x; M2[x]=k;
            SL[k]=1;
            return 1;
        }
    return 0;
}
void support (int k) { // cel din dreapta
    for (auto &x: v[k]) {
        if (! SR[x]) {
            SR[x]=1;
            SL[M2[x]]=0;
            support (M2[x]);
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        v[x].push_back(y);
    }

    cuplate=1;
    while (cuplate) {
        cuplate=0; ++G;
        for (i=1; i<=n; ++i)
            if (! M1[i]) cuplate+=cupleaza (i);
    }
    for (i=1; i<=n; ++i) if (M1[i]) ++sol;

    g<<2*n - sol<<"\n";

    for (i=1; i<=n; ++i)
        if (! SL[i]) support (i);

    for (i=1; i<=n; ++i) {
        if (SL[i]  &&  SR[i]) g<<"0\n";
        if (SL[i]  && !SR[i]) g<<"2\n";
        if (!SL[i] &&  SR[i]) g<<"1\n";
        if (!SL[i] && !SR[i]) g<<"3\n";
    }


    return 0;
}
