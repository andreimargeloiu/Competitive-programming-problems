# include <cstdio>
# include <algorithm>
using namespace std;
struct elem
{
    int a,b,c,i;
}v[30005],vv[30005];
int i,j,n,var,unu,doi,v1,v2;
int ap[30005];
int cmp1 (elem x, elem y)
{
    if (x.c>y.c) return 0;
        else if (x.c==y.c && x.a>=y.a) return 0;
            else return 1;
}
int cmp2 (elem x, elem y)
{
    if (x.c>y.c) return 0;
        else if (x.c==y.c && x.b>=y.b) return 0;
            else return 1;
}
int main ()
{
    freopen ("gramezi.in", "r", stdin);
    freopen ("gramezi.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d", &v[i].a, &v[i].b);
        v[i].c=v[i].a+v[i].b; v[i].i=i;
        vv[i]=v[i];
    }
    sort (v+1, v+n+1, cmp1);
    sort (vv+1, vv+n+1, cmp2);
    unu=0; doi=0;
    v1=n; v2=n; var=1;
    for (i=n; i>=1; --i)
    {
        if (var==1)
        {
            while (v1 && ap[v[v1].i])
                --v1;
            ap[v[v1].i]=1;
            unu+=v[v1].a;
            var=2;
        }
        else{
                while (v2 && ap[vv[v2].i])
                    --v2;
                ap[vv[v2].i]=1;
                doi+=vv[v2].b;
                var=1;
            }
    }
    printf ("%d %d\n", unu, doi);
    return 0;
}
