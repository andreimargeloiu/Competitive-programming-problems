# include <cstdio>
# include <algorithm>
# define NR 100005
using namespace std;

int i,j,n,m,p;
long long S[NR], a[NR],ci,cs,mij,sol,X;

bool cmp (int x, int y)
{
    if (x<=y) return 0;
         else return 1;
}

int verifica (long long K)
{
    //verificam daca se pot forma
    for (int i=1; i<=p; ++i) {
        if (S[i] < K*(p-i+1)) return 0;
        if (a[i]==K) return i;
        if (a[i]<=K) return i-1;
    }
    return p;
}

int main ()
{
    freopen ("sirag1.in", "r", stdin);
    freopen ("sirag1.out", "w", stdout);

    scanf ("%d%d", &n, &p);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    sort (a+1, a+n+1, cmp);
    for (i=n; i>=1; --i)
        S[i]=S[i+1] + a[i];

    //caut binar cate secvente de lungime p pot concatena
    ci=0; cs=S[1]/p;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verifica (mij)) X=mij, ci=mij+1;
                       else cs=mij-1;
    }

    //putem forma X secvente concatenate
    int poz=verifica (X); // -> returneaza pozitia pe care se termina bucatile stas

    sol=1LL*X*poz + S[poz+1];
    for (i=1; i<=poz; ++i)
        if (a[i]>X) ++sol;

    printf ("%lld", sol);

    return 0;
}
