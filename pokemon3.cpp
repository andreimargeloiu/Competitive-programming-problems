# include <bits/stdc++.h>
# define NR 10005
using namespace std;
ifstream f("pokemon3.in");
ofstream g("pokemon3.out");
int i,j,n,m,OK,sol,x,y,z,verif;
int bate[50], st[50];
void BACK (int k, int K, int ant) {
    if (OK) return;
    if (k==K+1) { //verifica
        if ((verif & ant) == verif) {
            OK=1; sol=K;
            return;
        }
    } else {
        for (int i=st[k-1]+1; i<=n; ++i) {
            st[k]=i;
            BACK(k+1, K, ant | bate[i]);
            st[k]=0;
        }
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j) {
            f>>x;
            if (x) bate[i]+=(1<<j);
        }
    for (i=1; i<=m; ++i) {
        f>>x>>y>>z;
        verif=verif | (1<<x);
        verif=verif | (1<<y);
        verif=verif | (1<<z);
    }

    OK=0; sol=-1;
    for (i=1; i<=n; ++i)
        if (! OK) BACK (1, i, 0);

    g<<sol<<"\n";

    return 0;
}
