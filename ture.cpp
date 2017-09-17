# include <fstream>
# include <algorithm>
# define NR 255
using namespace std;
ifstream f("ture.in");
ofstream g("ture.out");
int i,j,n,m,x,y,nou,act,K,k,S,P,maxx,nr,o,ok;
long long a[5][100000], sol;
int ap[NR][NR];
int main ()
{
    f>>n>>m>>K; if (n>m) {swap(n, m); ok=1;}
    f>>P;
    for (i=1; i<=P; ++i) {
        f>>x>>y; if (ok) swap(x, y);
        ap[x][y]=1;
    }
    // a[i][j] - numarul de moduri de a pune piese pe linii din bitii de 1
    //           ai lui j si primele i coloane
    act=1; nou=2; maxx=(1<<(n+1));

    for (i=1; i<=m; ++i) { //coloana
        for (o=1; o<=n; ++o) { //fiecare rand
            if (! ap[o][i]) {
                ++a[nou][1<<o];
                for (j=0; j<=maxx; ++j) { //fiecare stare
                        if (((1<<o) & j)==0) //daca randul nu se gaseste in starea respectiva
                            a[nou][j + (1<<o)]+=a[act][j];
                    }
                }
        }

        for (j=0; j<=maxx; ++j) {
            a[act][j]+=a[nou][j];
            a[nou][j]=0;
        }
    }

    for (i=0; i<=maxx; ++i) {
        nr=0;
        for (j=1; j<=n; ++j) if (i & (1<<j)) ++nr;

        if (nr==K) {
            sol+=a[act][i];
        }
    }
    g<<sol<<"\n";

    return 0;
}
