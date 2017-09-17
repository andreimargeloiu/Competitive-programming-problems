# include <fstream>
# include <algorithm>
# define NR 1005
using namespace std;
ifstream f("matperm2.in");
ofstream g("matperm2.out");
struct elem {
    int poz, X;
}ciclu[NR*NR], var[NR*NR];
int i,j,n,m,x,y,P,Q,x2,y2,L,I,N,xx;
int a[NR][NR], perm[NR*NR], poz[NR*NR], c[NR*NR];
bool ap[NR*NR];
void citire () {
    int i,j;
    f>>n>>m>>P; N=n*m;
    // pentru randuri
    for (i=1; i<=n; ++i) {
        f>>x;
        for (j=1; j<=m; ++j) {
            a[i][j]=(x-1)*m+j;

            c[(i-1)*m+j]=a[i][j];
        }
    }
    // pentru coloane
    for (j=1; j<=m; ++j) {
        f>>x;
        for (i=1; i<=n; ++i)
            a[i][j]=c[(i-1)*m+x];
    }
    f>>Q;
    for (i=1; i<=Q; ++i) {
        f>>x>>y>>x2>>y2;
        swap(a[x][y], a[x2][y2]);
    }
}
int main ()
{
    citire ();
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            perm[(i-1)*m+j]=a[i][j];

    //acum descompun in cicluri
    for (i=1; i<=N; ++i) {
        if (! ap[i]) { //un nou ciclu
            L=0; I=i;

            ++L; ap[I]=1;
            ciclu[L].poz=I;
            ciclu[L].X=perm[I];

            while (! ap[perm[I]]) {
                I=perm[I]; ap[I]=1;
                ++L;
                ciclu[L].poz=I;
                ciclu[L].X=perm[I];
            }

            if (P%L==0) {//pemutarea identica
                for (j=1; j<=L; ++j)
                    perm[ciclu[j].poz]=ciclu[j].poz;
            }
            else { //ridica la puterea P % L
                xx=P%L;
                for (j=1; j<=L; ++j)
                    if ((j+xx-1)%L==0) perm[ciclu[j].poz]=ciclu[L].X;
                                  else perm[ciclu[j].poz]=ciclu[(j+xx-1)%L].X;
            }
        }
    }
    for (i=1; i<=n; ++i) {
        for (j=1; j<=m; ++j)
            g<<perm[(i-1)*m + j]<<" ";
        g<<"\n";
    }

    return 0;
}
