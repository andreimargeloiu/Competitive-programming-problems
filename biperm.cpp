# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,x,sol,act,next,nr,VV,minn,l;
int a[10005][2],f[10005],s[10005],ap[10005];
void citire ()
{
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x); a[i][0]=x;
        if (f[x]) s[x]=i;
            else  f[x]=i;
    }
    for (i=1; i<=n; ++i)
    {
        scanf ("%d", &x); a[i][1]=x;
        if (f[x]) s[x]=i;
            else  f[x]=i;
    }
}
int main ()
{
    freopen ("biperm.in", "r", stdin);
    freopen ("biperm.out", "w", stdout);
    scanf ("%d", &n);
    citire();
    for (i=1; i<=n; ++i)
    {
        if (a[i][0]==a[i][1]) continue;
        if (ap[i]) continue;
        act=i; sol=0; l=0; nr=a[i][0]; ++VV;
        for(;;)
        {
            ap[act]=1; ++l;
            nr=a[act][0]+a[act][1]-nr ;
            next=f[nr]+s[nr]-act;
            if (next==i) break;
            if (a[act][1]!=a[next][0]) {++sol; swap(a[next][0],a[next][1]);}
            act=next;
        }
        minn+=min(sol,l-sol);
    }

    VV=1<<VV; printf("%d ",VV); printf("%d\n",minn);
    for(i=1; i<=n; ++i) printf("%d ",a[i][0]);printf("\n");
    for(i=1; i<=n; ++i) printf("%d ",a[i][1]);printf("\n");
    return 0;
}
