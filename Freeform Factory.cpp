# include <bits/stdc++.h>
# define INF 123123123
# define NR 1005
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,m,T,cost;
int sol,X[NR],V[NR],aux[NR][NR];
char M[NR][NR];
void BACK (int k) {
    if (k==n*n+1) {
        // cum verific ?

        for (int i=1; i<=n; ++i) {
            int VV=0;
            for (int j=1; j<=n; ++j) {
                if (aux[i][j]==1) V[++VV]=j;
            }

            if (VV==0) return;

            int Q=0;
            for (int j=1; j<=n; ++j)
                if (j!=i) X[++Q]=j;
            X[Q+1]=0; X[Q+2]=0; X[Q+3]=0; X[Q+4]=0;

            // acum verific
            if (VV==1) {
                if (aux[X[1]][V[1]] || aux[X[2]][V[1]] || aux[X[3]][V[1]]) return;
            }
            if (VV==2) {
                if ((aux[X[1]][V[1]] || aux[X[2]][V[1]] || aux[X[3]][V[1]]) &&
                     (aux[X[1]][V[2]] || aux[X[2]][V[2]] || aux[X[3]][V[2]]))
                     return;
            }
            if (VV==3) {
                 if ((aux[X[1]][V[1]] || aux[X[2]][V[1]] || aux[X[3]][V[1]]) &&
                     (aux[X[1]][V[2]] || aux[X[2]][V[2]] || aux[X[3]][V[2]]) &&
                     (aux[X[1]][V[3]] || aux[X[2]][V[3]] || aux[X[3]][V[3]]))
                     return;
            }
        }

        if (cost < sol) sol=cost;

    } else {
        int L=(k-1)/n+1;
        int C=(k-1)%n+1;

        if (M[L][C]=='1') {
            aux[L][C]=1;
            BACK(k+1);
            aux[L][C]=0;
        } else {
            //il iau
            aux[L][C]=1; ++cost;
            BACK(k+1);
            aux[L][C]=0;

            // nu il iau
            aux[L][C]=0;
            BACK(k+1);
        }
    }
}
void init() {
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            aux[i][j]=0;
}
int main ()
{
    f>>T; int test=0;
    while (T--) {
        ++test; g<<"Case #"<<test<<": ";

        f>>n; f.get(); init();
        for (int i=1; i<=n; ++i)
            f.getline(M[i]+1, NR);

        sol=INF; cost=0;
        BACK (1);
        g<<sol<<"\n";
    }



    return 0;
}
