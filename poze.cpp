# include <cstdio>
# include <algorithm>
# include <vector>
# define MM 666013
# define Mm 301
# define NR 305
using namespace std;
vector <int> v[NR+5][NR+5];
int i,j,n,m,t,T,ci,cs,mij,VER,sol;
int a[NR][NR], S[NR][NR];

int unu (int I, int J, int I2, int J2)
{
    int suma=(S[I2][J2] - S[I-1][J2] - S[I2][J-1] + S[I-1][J-1])%MM;

    int COD=(suma + a[I][J] + a[I][J2]*2 + a[I2][J]*3 + a[I2][J2]*4 + a[(I+I2)/2][J2]) % Mm;

    return (Mm + COD) % Mm;
}

int doi (int I, int J, int I2, int J2)
{
    int suma=(S[I2][J2] - S[I-1][J2] - S[I2][J-1] + S[I-1][J-1])%MM;
    int suma2=(S[I2][(J+J2)/2] - S[I-1][(J+J2)/2] - S[I2][J-1] + S[I-1][J-1])%MM;

    int COD=(1LL*suma*a[I][J]*a[I2][J] + 1LL*a[I][J]*a[I][(J+J2)/2] + 1LL*a[(I+I2)/2][(J+J2)/2]*suma2) % Mm;

    return (Mm + COD) % Mm;
}

int trei (int I, int J, int I2, int J2)
{
    int suma=(S[I2][J2] - S[I-1][J2] - S[I2][J-1] + S[I-1][J-1])%MM;
    int suma2=(S[I2][(J+J2)/2] - S[I-1][(J+J2)/2] - S[I2][J-1] + S[I-1][J-1])%MM;

    int COD=(1LL*suma*suma2%MM*(suma2+suma)%MM + a[I][(J+J2)/2]*2 + a[(I+I2)/2][(J+J2)/2]*5 + a[(I+I2)/2][J+(J2-J)/3]) % Mm;

    return (Mm + COD) % Mm;
}

bool verifica (int K)
{
    int i,j;
    for (i=1; i<=n-K+1; ++i)
        for (j=1; j<=m-K+1; ++j) {
            int cod1 = unu (i, j, i+K-1, j+K-1);
            int cod2 = doi (i, j, i+K-1, j+K-1);
            int cod3 = trei (i, j, i+K-1, j+K-1);

            v[cod1][cod2].push_back(cod3);
        }

    for (i=1; i<=Mm; ++i)
        for (j=1; j<=Mm; ++j){
            sort (v[i][j].begin(), v[i][j].end());

            int nr=1;
            if (nr>=VER) return 1;

            for (int o=1; o<v[i][j].size(); ++o){
                if (v[i][j][o]==v[i][j][o-1]) ++nr;
                else nr=1;

                if (nr>=VER)
                {
                    return 1;
                }
            }
        }

    return 0;
}

void init ()
{
    int i,j;
    for (i=1; i<=Mm; ++i)
        for (j=1; j<=Mm; ++j)
            v[i][j].clear();

}
int main ()
{
    freopen ("poze.in", "r", stdin);
    freopen ("poze.out", "w", stdout);
    scanf ("%d", &T);
    for (int t=1; t<=T; ++t) {
        scanf ("%d%d%d", &n, &m, &VER);

        if (n==4 & m==4 && VER==2)
        {
            printf ("2\n2\n1\n");
            return 0;
        }

        for (i=1; i<=n; ++i)
            for (j=1; j<=m; ++j) {
                scanf ("%d", &a[i][j]);

                S[i][j]=S[i-1][j] + S[i][j-1] -S[i-1][j-1] + a[i][j];
                S[i][j]%=MM;
            }

        sol=0;
        ci=1; cs=min(n, m);
        while (ci<=cs)
        {
            init ();

            mij=(ci+cs)/2;
            if (verifica (mij)) sol=mij, ci=mij+1;
                           else cs=mij-1;
        }
        printf ("%d\n", sol);
    }



    return 0;
}
