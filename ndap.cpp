# include <bits/stdc++.h>
# define MOD 30103
# define N 20
using namespace std;
ifstream f("ndap.in");
ofstream g("ndap.out");
int i,j,n,m,x,y;
int conex[1<<N], neconex[1<<N], nrm[1<<N], M[N][N], P[N*N];

void make_conex (int S) {
    conex[S]=((P[nrm[S]] - neconex[S]) % MOD + MOD)%MOD;
}
void CONEX () {
    int S,j,X,mask;
    for (S=1; S<(1<<n); ++S) {
        X=S & (-S); //un bit aleator

        for (mask=S; mask!=0; mask=(mask-1) & S) //toate submultimile lui S
            if ((X & mask) && mask!=S) { // daca X face parte din aceasta comp conexa
                neconex[S]=(neconex[S] + conex[mask] * P[nrm[S - mask]])%MOD;
            }
        make_conex (S);
    }
}
void puteri () {
    P[0]=1;
    for (int i=1; i<=n*n; ++i)
        P[i]=(P[i-1] * 2) %MOD;
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y;
        M[x][y]=1;
        M[y][x]=1;

        for (j=1; j<(1<<n); ++j)
            if ((j & (1<<x)) && (j & (1<<y)))
                ++nrm[j];
    }
    // facem numarul de muchii
    puteri ();
    CONEX ();
    g<<conex[(1<<n) - 1]<<"\n";

    return 0;
}
