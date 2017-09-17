# include <cstdio>
# include <vector>
# include <algorithm>
# define NR 100005
using namespace std;

int i,j,n,m,xy,med,mici,mari,ok,CI,CS,K,I;
int nr[4*NR], a[NR], P[NR];
long long minn, cost, Sm, SM, ARB[4*NR];

void update (int nod, int ci, int cs, int x)
{
    if (ci==cs)
    {
        nr[nod]+=ok; ARB[nod]=ARB[nod] + ok*x;
    }
    else {
             int mij=(ci+cs)/2;
             if (x<=P[mij]) update (2*nod, ci, mij, x);
             if (x>P[mij])  update (2*nod+1, mij+1, cs, x);

             nr[nod]=nr[2*nod] + nr[2*nod+1];
             ARB[nod]=ARB[2*nod] + ARB[2*nod+1];
         }
}
void suma (int nod, int ci, int cs, long long &S, int &numar)
{
    if (CI<=ci && cs<=CS)
    {
        S+=ARB[nod]; numar+=nr[nod];
    }
    else {
             int mij=(ci+cs)/2;
             if (CI<=mij) suma (2*nod, ci, mij, S, numar);
             if (CS>mij)  suma (2*nod+1, mij+1, cs, S, numar);
         }
}
void mediana (int nod, int ci, int cs, int R)
{
    if (ci==cs) I=ci;
    else {
             int mij=(ci+cs)/2;
             if (R<=nr[2*nod]) mediana (2*nod, ci, mij, R);
             else              mediana (2*nod+1, mij+1, cs, R-nr[2*nod]);
         }
}
int main ()
{
    freopen ("pikachu.in", "r", stdin);
    freopen ("pikachu.out", "w", stdout);
    scanf ("%d%d", &n, &K);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &a[i]);
        P[i]=a[i];
    }
    sort (P+1, P+n+1);

    for (i=0; i<K; ++i)
    {
        ok=1;
        update (1, 1, n, a[i]);
    }

    minn=1LL<<61;
    for (i=K; i<=n; ++i)
    {
        //facem update-urile
        ok=-1; update (1, 1, n, a[i-K]);
        ok=1;  update (1, 1, n, a[i]);

        mediana (1, 1, n, (K+1)/2);

        med=P[I];
        mici=0; mari=0;
        Sm=0;   SM=0;

        CI=1;   CS=I-1;  suma (1, 1, n, Sm, mici);
        CI=I+1; CS=n;    suma (1, 1, n, SM, mari);

        cost=(1LL*mici*med - Sm) + (SM - 1LL*mari*med);
        minn=min(minn, cost);
    }
    printf ("%lld\n", minn);

    return 0;
}
