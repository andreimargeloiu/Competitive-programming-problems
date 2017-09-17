# include <cstdio>
# include <algorithm>
# include <bitset>
using namespace std;
struct elem
{
    int x,y,val,ap;
}v[5005];
int cmp (elem x, elem y)
{
    if (x.x>y.x) return 0;
        else if (x.x==y.x && x.y>y.y) return 0;
             else return 1;
}
int cmp2 (elem x, elem y)
{
    if (x.ap>y.ap) return 0;
        else return 1;
}
int i,j,n,m,l,c,VV,x,nr,QQ,Q2,k,var;
char ch;
int main ()
{
    freopen ("robot4.in", "r", stdin);
    freopen ("robot4.out", "w", stdout);
    scanf ("%d%d%d%d", &n, &m, &l, &c);
    v[++VV].x=l; v[VV].y=c; v[VV].ap=1;
    scanf ("\n");
    for (i=1; i<=m; ++i)
    {
        scanf ("%c ", &ch);
        if (ch=='N') --l;
        if (ch=='E') ++c;
        if (ch=='S') ++l;
        if (ch=='V') --c;
        v[++VV].x=l; v[VV].y=c; v[VV].ap=i+1;
    }
    sort (v+1,v+VV+1,cmp);
    var=1;
    for (i=1; i<=n; ++i)
        for (j=1; j<=n; ++j)
        {
            scanf ("%d", &x);
            if (v[var].x==i && v[var].y==j) v[var].val=x,++var;
        }
    sort (v+1,v+VV+1,cmp2);
    for (i=1; i<=VV; ++i)
    {
        QQ+=v[i].val;
        if (QQ==0)
        {
            printf ("%d %d\n", v[i].x, v[i].y);
            return 0;
        }
        --QQ;
    }
    printf ("%d %d\n", v[VV].x, v[VV].y);
    return 0;
}
