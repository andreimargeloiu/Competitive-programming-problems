# include <fstream>
# include <algorithm>
# define MOD 666013
# define NR (1<<21)+5
# define N 21
using namespace std;
ifstream f("android.in");
ofstream g("android.out");
int i,j,n,m,nre;
int SOL, sol[NR][N], P[N][N];
bool ok (int x, int y) {
    if (1<=x && x<=n && 1<=y && y<=m) return 1;
                                 else return 0;
}
void make (int I, int J, int xx, int yy) {
    int i,j,X,Y,dx,dy,ant,nr2,nr1=(I-1)*m + J-1;
    for (dx=0; dx!=xx*n; dx+=xx)
        for (dy=0; dy!=yy*m; dy+=yy) {
            if (dx==0 && dy==0) continue;
            X=I; Y=J; ant=nr1;

            while (ok(X+dx, Y+dy)) {
                X+=dx; Y+=dy;
                nr2=(X-1)*m + Y-1;
                if (P[nr1][nr2]) break;

                P[nr1][nr2]=P[nr1][ant] + (1<<ant);

                ant=nr2;
            }
        }
}
void pattern () {
    int i,j,dx,dy,X,Y,ant,nr1,nr2;
    for (i=1; i<=n; ++i) {
        for (j=1; j<=m; ++j) {
            make (i, j, 1, 1);
            make (i, j, 1, -1);
            make (i, j, -1, 1);
            make (i, j, -1, -1);
        }
    }
}
void dinamica () {
    int i, stare, k, urm;
    for (stare=1; stare<=(1<<nre); ++stare) {
        for (k=0; k<nre; ++k) {
            if ((1<<k) & stare) {
                for (i=0; i<nre; ++i) {
                    if (i==k) continue;

                    if ((1<<i) & stare) {
                        if ((stare & P[i][k])==P[i][k]) {
                            sol[stare][k] = (sol[stare][k] + sol[stare - (1<<k)][i])%MOD;
                        }
                    }
                }
            }
            SOL=(SOL + sol[stare][k])%MOD;
        }

    }
}
int main ()
{
    f>>n>>m; nre=n*m;

    pattern ();
    for (i=0; i<nre; ++i) {
        sol[1<<i][i]=1;
    }
    dinamica ();

    g<<SOL<<"\n";

    return 0;
}
