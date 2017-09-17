# include <cstdio>
# include <algorithm>
# include <cmath>
# define NR 105
using namespace std;
struct elem {
    int i,j;
}a[NR][NR];
int i,j,n,m,l,maxx;
short x,y,x2,y2,I,I2,J,J2,H;
int M[NR][NR], Mcomun[NR][NR], LM[NR][NR], LMcomun[NR][NR], CM[NR][NR], CMcomun[NR][NR], A[NR][NR];
short lin[NR], col[NR], L[NR];
void init (int l){
    for (int i=1; i<=n; ++i) {
        col[i]=(i-1)/l+1;
        lin[i]=(i-1)/l+1;
    }

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            a[i][j].i=lin[i];
            a[i][j].j=col[j];
        }
}
int Linie () {
    for (int i=1; i<=n; ++i)
       L[i]=(i-1)*l+1;
}
int getmax (short x, short y, short x2, short y2)
{
    int i,j;
    int maxx=0,ok;

    // bucatile mari
    for (i=I; i<=I2; ++i)
        for (j=J; j<=J2; ++j)
            maxx=max(maxx, M[i][j]);

    //liniile
    for (i=x; i<=x2; ++i) {
        if (i==L[I]) i=I2*l+1;
        if (i>x2) break;
        j=y; ok=1;
        while (j<=y2) {
            if (j==L[J]) ok=l;
            if (j==L[J2+1]) ok=1;

            if (ok==1)
            {
                if (maxx < Mcomun[lin[i]][col[j]]) maxx=Mcomun[lin[i]][col[j]];
                if (maxx < CMcomun[lin[i]][j]) maxx=CMcomun[lin[i]][j];
                if (maxx < LMcomun[i][col[j]]) maxx=LMcomun[i][col[j]];
                if (maxx < A[i][j]) maxx=A[i][j];
            }
            else
            {
                if (maxx < LM[i][col[j]]) maxx=LM[i][col[j]];
                if (maxx < Mcomun[lin[i]][col[j]]) maxx=Mcomun[lin[i]][col[j]];
            }
            j+=ok;
        }
    }

    //coloanele
    for (j=y; j<=y2; ++j) {
        if (j==L[J]) j=J2*l+1;
        if (j>y2) break;
        i=x; ok=1;
        while (i<=x2) {
            if (i==L[I]) ok=l;
            if (i==L[I2+1]) ok=1;

            if (ok==1)
            {
                if (maxx < Mcomun[lin[i]][col[j]]) maxx=Mcomun[lin[i]][col[j]];
                if (maxx < CMcomun[lin[i]][j]) maxx=CMcomun[lin[i]][j];
                if (maxx < LMcomun[i][col[j]]) maxx=LMcomun[i][col[j]];
                if (maxx < A[i][j]) maxx=A[i][j];
            }
            else
            {
                if (maxx < CM[lin[i]][j]) maxx=CM[lin[i]][j];
                if (maxx < Mcomun[lin[i]][col[j]]) maxx=Mcomun[lin[i]][col[j]];
            }

            i+=ok;
        }
    }

    return maxx;
}
void update (short x, short y, short x2, short y2, int H)
{
    int i,j,maxx=0,ok;

    // bucatile mari
    for (i=I; i<=I2; ++i)
        for (j=J; j<=J2; ++j) {
            M[i][j]=H;
            Mcomun[i][j]=H;
        }

    //liniile
    for (i=x; i<=x2; ++i) {
        if (i==L[I]) i=I2*l+1;
        if (i>x2) break;

        if (i==x || i==x2) {
            for (j=y; j<=y2; ++j)
                if (H > CM[lin[i]][j]) CM[lin[i]][j]=H;
        }

        j=y; ok=1;
        while (j<=y2) {
            if (j==L[J]) ok=l;
            if (j==L[J2+1]) ok=1;


            if (H > M[lin[i]][col[j]]) M[lin[i]][col[j]]=H;
            if (H > LM[i][col[j]]) LM[i][col[j]]=H;

            if (ok==1) A[i][j]=H;
                  else LMcomun[i][col[j]]=H;

            j+=ok;
        }
    }

    //coloanele
    for (j=y; j<=y2; ++j) {
        if (j==L[J]) j=J2*l+1;
        if (j>y2) break;

        if (j==y || j==y2) {
            for (i=x; i<=x2; ++i)
                if (H > LM[i][col[j]]) LM[i][col[j]]=H;
        }

        i=x; ok=1;
        while (i<=x2) {
            if (i==L[I]) ok=l;
            if (i==L[I2+1]) ok=1;

            if (H > M[lin[i]][col[j]]) M[lin[i]][col[j]]=H;
            if (H > CM[lin[i]][j]) CM[lin[i]][j]=H;

            if (ok==1) A[i][j]=H;
                  else CMcomun[lin[i]][j]=H;

            i+=ok;
        }
    }
}
int main ()
{
    freopen ("blockout.in", "r", stdin);
    freopen ("blockout.out", "w", stdout);

    scanf ("%d%d", &n, &m); ++n; l=sqrt((double)(n));
    init (l); Linie();
    for (i=1; i<=m; ++i) {
        scanf ("%d%d%d%d%d", &x, &y, &x2, &y2, &H);

        ++x; ++y; ++x2; ++y2;

        I=lin[x]; J=col[y];
        if (x > L[I]) ++I;
        if (y > L[J]) ++J;

        I2=lin[x2]; J2=col[y2];
        if (x2 < I2*l) --I2;
        if (y2 < J2*l) --J2;

        maxx=getmax(x, y, x2, y2); printf ("%d\n", maxx);

        update (x, y, x2, y2, maxx+H);
    }

    return 0;
}
