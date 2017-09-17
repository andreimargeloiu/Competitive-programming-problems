# include <cstdio>
# include <algorithm>
# define NR 100005
using namespace std;
int i,j,n,rez,S,act,nou;
int var[NR], ap[NR], g[NR];
int main ()
{
    freopen ("viena.in", "r", stdin);
    freopen ("viena.out", "w", stdout);

    scanf ("%d", &n);
    for (i=1; i<=n; ++i) {
        scanf ("%d", &g[i]);
        S+=g[i];
    }

    var[++act]=0;
    for (i=1; i<=n; ++i) {
        nou=act;

        //le prelucrez pe actualele
        for (j=1; j<=act; ++j) {
            if (! ap[var[j]+g[i]]) var[++nou]=var[j]+g[i], ap[var[j]+g[i]]=1;
            if (g[i]%2==0 && ! ap[var[j]+g[i]/2]) var[++nou]=var[j]+g[i]/2, ap[var[j]+g[i]/2]=1;
        }
        act=nou;
    }
    rez=NR+5;
    for (i=1; i<=act; ++i)
        rez=min(rez, max(var[i], S-var[i]));

    printf ("%d\n", rez);

    return 0;
}
