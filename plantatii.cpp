# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1005
using namespace std;
ifstream f("plantatii.in");
ofstream g("plantatii.out");
int i,j,n,m,x,y,imp,par,T,W;
int P[NR][NR], S[NR][NR], a[NR][NR];
void bordare (int N) {
    for (int i = 0; i <= N + 1; i++) {
        P[i][0] = P[i][N + 1] = 0;
        P[0][i] = P[N + 1][i] = 0;
        S[i][0] = S[i][N + 1] = 0;
        S[0][i] = S[N + 1][i] = 0;
    }
}
bool verifica (int I, int J, int k) {
    if (I-k+1<1 || J-k+1<1) return 0;

    int suma=0;
    suma=P[I][J]-P[I-k][J-k] + S[I][J-k+1]-S[I-k][J+1];

    if (k%2==1 && k>1) suma-=a[I-k/2][J-k/2];
    if (suma>W) return 0;

           else return 1;
}
int main ()
{
    f>>T;
    for (int t=1; t<=T; ++t) {
        f>>n>>W; bordare (n);
        imp=-1; par=0;
        for (i=1; i<=n; ++i) {
            for (j=1; j<=n; ++j) {
                f>>x; a[i][j]=x;
                P[i][j]=P[i-1][j-1]+x;
                S[i][j]=S[i-1][j+1]+x;
            }

            for (j=1; j<=n; ++j) {
                while (verifica (i, j, imp+2))
                     imp+=2;
                while (verifica (i, j, par+2))
                     par+=2;
            }
        }
        g<<max(par,imp)<<"\n";
    }



    return 0;
}
