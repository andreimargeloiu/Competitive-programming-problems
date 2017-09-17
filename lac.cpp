# include <cstdio>
# include <algorithm>
# define NR 100005
using namespace std;
int i,j,n,m,L,l,x1,x2,y,cs,next,maxx;
int main ()
{
    freopen ("lac.in", "r", stdin);
    freopen ("lac.out", "w", stdout);
    scanf ("%d%d%d", &L, &l, &n);
    cs=0;
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d%d", &y, &x1, &x2);
        if (x1<=cs)
        {
            if (x2>next) next=x2;
        }
        else {
                 cs=next; next=0; ++maxx;
                 if (x1<=cs)
                 {
                     if (x2>next) next=x2;
                 }
                 else
                 {
                     printf ("0\n");
                     return 0;
                 }
             }
    }
    if (next>cs) cs=next, ++maxx;
    if (cs<L) printf ("0\n");
        else printf ("%d\n", n-maxx+1);

    return 0;
}
