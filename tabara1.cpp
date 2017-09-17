# include <cstdio>
# include <algorithm>
# define NR 30005
using namespace std;
int i,j,n,m,x,VV,ci,cs,mij,poz;
int ap[NR], a[NR], st[NR];
int main ()
{
    freopen ("tabara1.in", "r", stdin);
    freopen ("tabara1.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x);
        ap[x]=i;
    }
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x);
        a[ap[x]]=i;
    }

    for (i=1; i<=n; ++i)
    {
        if (a[i]>st[VV]) st[++VV]=a[i];
        else {
                 ci=1; cs=VV; poz=VV;
                 while (ci<=cs)
                 {
                     mij=(ci+cs)/2;
                     if (st[mij]<a[i]) ci=mij+1;
                     else cs=mij-1, poz=mij;
                 }
                 st[poz]=a[i];
             }
    }
    printf ("%d\n", VV);

    return 0;
}
