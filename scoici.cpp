# include <cstdio>
# include <algorithm>
# define inf 999999999
# define NR 100005
using namespace std;
int i,j,n,m,x,y,maxx,C,X,minn,ci,cs;
int a[NR][12], ind[NR];
bool cmp (int I, int J)
{
    for (int i=1; i<=C; ++i)
        if (a[I][i]>a[J][i]) return 0;
        else if (a[I][i]<a[J][i]) return 1;

    if (I>=J) return 0;
         else return 1;
}
bool egal (int I, int J)
{
    for (int i=1; i<=C; ++i)
        if (a[I][i]!=a[J][i]) return 0;

    return 1;
}
int main ()
{
    freopen ("scoici.in", "r", stdin);
    freopen ("scoici.out", "w", stdout);
    scanf ("%d%d", &n, &C);

    // ap[i][j] - de cate ori apare elemntul j pana la pozitia i

    for (i=1; i<=n; ++i) {
        scanf ("%d", &X);
        for (j=1; j<=C; ++j)
            a[i][j]=a[i-1][j];

        ++a[i][X]; minn=inf;

        for (j=1; j<=C; ++j)
            minn=min(minn, a[i][j]);

        for (j=1; j<=C; ++j)
            a[i][j]-=minn;

        ind[i]=i;
    }

    sort (ind+1, ind+n+1, cmp);

    maxx=0;
    ci=1; cs=0;
    for (i=1; i<=n; ++i) {
        if (egal (ind[i-1], ind[i])) ++cs;
        else {
                 maxx=max(maxx, ind[cs]-ind[ci]);
                 ci=i; cs=i;

             }
    }
    printf ("%d\n", maxx);
    return 0;
}
