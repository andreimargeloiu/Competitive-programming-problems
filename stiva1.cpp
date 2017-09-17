# include <cstdio>
# include <cstring>
# include <algorithm>
# define inf 2000000005
# define NR 50005
using namespace std;
int i,j,n,m,minn,maxx,maxst,VV,ST,P,ok,poz;
int a[NR], st[NR], perm[NR], ap[NR];
int main ()
{
    freopen ("stiva1.in", "r", stdin);
    freopen ("stiva1.out", "w", stdout);
    scanf ("%d", &n);

    for (int t=1; t<=5; ++t) {
        minn=inf;
        for (i=1; i<=n; ++i) {
            scanf ("%d", &a[i]);
            minn=min(minn, a[i]);
        }

        maxst=0; maxx=0; memset (ap, 0, sizeof(ap));
        for (i=1; i<=n; ++i) {
            a[i]=a[i]-minn+1;
            ap[a[i]]=1;
            if (! ap[1]) maxst=max(maxst, a[i]);

            maxx=max(maxx, a[i]);
        }
        VV=0; memset (perm, 0, sizeof(perm));

        for (i=1; i<=maxst; ++i)
            if (! ap[i]) perm[++VV]=i;
        for (i=1; i<=n; ++i)
            perm[++VV]=a[i];
        for (i=maxx; i>=1; --i)
            if (! ap[i]) perm[++VV]=i;

        // acum simulez sa verific

        ok=1; ST=0; memset (st, 0, sizeof(st)); poz=1; P=0;
        for (i=1; i<=2*maxx && ok; ++i) {
            if (st[ST]==perm[poz]) {st[ST]=0; --ST; ++poz;}
            else if (P!=maxx) {
                ++P;
                st[++ST]=P;
            }
            else ok=0;
        }

        printf ("%d\n", ok);
    }


    return 0;
}
