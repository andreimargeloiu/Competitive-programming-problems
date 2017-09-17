# include <cstdio>
# include <algorithm>
# include <cstring>
using namespace std;
int ci,cs,maxx,VV,i,j,n,mij,l,lmax,cnt;
int a[10][50005],L[10];
long long v,nr,put[100];
char s[50005];
struct elem
{
    int i;
    long long nr;
}E,sol[3000005];
int cmp (elem x, elem y)
{
    if (x.nr>y.nr) return 0;
        else if (x.nr==y.nr && x.i>y.i) return 0;
            else return 1;
}
int verificare ()
{
    VV=0;
    for (int i=1; i<=n; ++i)
    {
        if (mij>L[i]) return 0;
        nr=0;
        for (j=1; j<=mij; ++j)
            nr=nr*2+a[i][j];
        E.i=i; E.nr=nr;
        sol[++VV]=E;
        for (int j=mij+1; j<=L[i]; ++j)
        {
            nr=(nr-put[mij-1]*a[i][j-mij])*2+a[i][j];
            E.i=i; E.nr=nr;
            sol[++VV]=E;
        }
    }
    sort (sol+1, sol+VV+1, cmp);
    sol[0].nr=-1; cnt=1;
    int maxx=0;
    for (int i=1; i<=VV; ++i)
    {
        if (sol[i].nr==sol[i-1].nr)
        {
            if (sol[i].i==sol[i-1].i) continue;
                else ++cnt;
        }
        else {
                 maxx=max(maxx, cnt);
                 cnt=1;
             }
    }
    if (maxx==n) return 1;
        else return 0;
}
void putere ()
{
    put[0]=1;
    for (int i=1; i<=min(lmax,60); ++i)
        put[i]=put[i-1]*2;
}
int main ()
{
    freopen ("subsecvente.in", "r", stdin);
    freopen ("subsecvente.out", "w", stdout);
    scanf ("%d \n", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%s\n", &s);
        l=strlen(s); L[i]=l;
        lmax=max(l,lmax);
        for (j=0; j<l; ++j)
            a[i][j+1]=s[j]-'a';
    }
    putere ();
    ci=1; cs=min(60,lmax);
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (verificare ()) maxx=mij,ci=mij+1;
           else cs=mij-1;
    }
    printf ("%d\n", maxx);
    return 0;
}
