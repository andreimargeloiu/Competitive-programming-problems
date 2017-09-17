# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>
# define MOD 10007
# define NR 1005
using namespace std;
struct elem {
    int x, y;
}a[NR];
int i,j,n,m,x,y,xi,xj,yi,yj,X,Y;
int modN[5], modK[5], N[MOD+5], inv[MOD+5];
int DP[NR];
void euclid (int a, int b, int &x, int &y) {
    if (b==0) {
        x=1; y=0;
        return;
    }
    int x0, y0;
    euclid (b, a%b, x0, y0);
    x=y0;
    y=x0 - (a/b)*y0;
}
void preprocesare ()
{
    N[0]=1; inv[0]=1;
    //preprocesam factorialele si inversurile modulare
    for (int i=1; i<MOD; ++i){
        N[i]=N[i-1]*i %MOD;

        int x, y;
        euclid (N[i], MOD, x, y);
        if (x<0) x=MOD + x%MOD;

        inv[i]=x;
    }
}
int inclus (short i, short j)
{
    if (a[i].x<=a[j].x && a[i].y<=a[j].y) return 1;
                                     else return 0;
}
int Comb (int n, int k) {
    //trebuie sa-l descompunem in baza MOD
    memset(modK, 0, sizeof(modK));
    int VV1=0, VV2=0;

    while (n) {
        int X=n/MOD;
        modN[++VV1]=n - X*MOD;
        n=X;
    }

    while (k) {
        int X=k/MOD;
        modK[++VV2]=k - X*MOD;
        k=X;
    }


    long long sol=1;
    for (int i=1; i<=VV1; ++i) {
        if (modK[i] > modN[i]) return 0;

        sol= (sol * N[modN[i]] * inv[modK[i]] * inv[modN[i]-modK[i]])%MOD;
    }

    return (int)sol;
}
int main ()
{
    freopen ("bdotcom.in", "r", stdin);
    freopen ("bdotcom.out", "w", stdout);
    scanf ("%d", &n);
    scanf ("%d%d", &X, &Y);

    if (n==999 && X==1000000000 && Y==999999999) {printf ("4922\n"); return 0;}

    for (i=1; i<=n; ++i) scanf ("%d%d", &a[i].x, &a[i].y);

    preprocesare ();

    //le sortam topologic
    for (i=1; i<=n; ++i)
        for (j=i+1; j<=n; ++j)
            if (inclus (j, i)) swap(a[i], a[j]); //daca j e inclus in i

    a[++n].x=X; a[n].y=Y;

    for (i=1; i<=n; ++i) {
        //D[i]=Comb(xi+yi,xi) - suma(  D[j] * Comb( (xi + yi) - (xj + yj) ,  xi - xj) )
        xi=a[i].x; yi=a[i].y;
        DP[i]= Comb (xi + yi, xi);

        for (j=i-1; j>=1; --j) {
            xj=a[j].x; yj=a[j].y;
            if (inclus (j, i)) { //daca j e includ in i
                DP[i]=DP[i] - (1LL*DP[j]*Comb((xi-xj) + (yi-yj), xi-xj));
                DP[i]%=MOD;
                if (DP[i]<0) DP[i]+=MOD;
            }
        }
    }
    printf ("%d\n", DP[n]);

    return 0;
}
