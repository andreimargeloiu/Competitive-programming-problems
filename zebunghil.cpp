# include <fstream>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("zebughil.in");
ofstream g("zebughil.out");
struct elem {
    int X, C;
}a[NR];
int i,j,n,m,x,y,stop,G,antC,antX,nou;
int nr[1000];
int main ()
{
    for (int t=1; t<=3; ++t) {
        f>>n>>G;
        for (i=1; i<=n; ++i)
            f>>nr[i];

        stop=(1<<(n+1))-2;
        for (i=1; i<=stop; ++i) {
            a[i].C=n+1; a[i].X=0;

            for (j=1; j<=n; ++j)
                if ((1<<j) & i) { // daca se afla in configuratie

                    antC=a[i-(1<<j)].C; antX=a[i-(1<<j)].X;

                    int ok=0;
                    if (antX + nr[j] > G) ok=1;

                    if (ok==1) nou=nr[j];
                          else nou=antX + nr[j];

                    if (antC + ok < a[i].C || (antC + ok == a[i].C && nou<a[i].X)) {
                        a[i].C=antC+ok;
                        a[i].X=nou;
                    }
                }
        }

        g<<1 + a[stop].C<<"\n";
    }

    return 0;
}
