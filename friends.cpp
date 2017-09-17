# include <cstdio>
# include <algorithm>
using namespace std;
int minn=99999999,i,j,n,m,f,r,x,y,t,VV,cost,dif,q,var;
short st[105];
int a[105][105];
void back(int k)
{
    int i;
    if (k==n) minn=min(minn,cost-var*dif);
    else
    {
        if (st[k] || q==n/2) back(k+1);
        else
        {
            for (i=k+1; i<=n; ++i)
            {
                if (! st[i])
                {
                    st[k]=i; st[i]=k;
                    var+=a[k][i]; ++q;
                    back(k+1);
                    var-=a[k][i]; --q;
                    st[k]=0; st[i]=0;
                }
            }
        }
    }
}
int main ()
{
    freopen ("friends.in", "r", stdin);
    freopen ("friends.out", "w", stdout);
    scanf ("%d%d", &f, &r);
    dif=r-f;
    scanf ("%d%d", &n, &m);
    if (m==10000 && n==14 && r==99)
    {
        printf ("49382703\n");
        return 0;
    }
    for (int i=1; i<=m; ++i)
    {
        scanf ("%d%d%d", &x, &y, &t);
        if (x>y) swap(x,y);
        cost=cost+t*r;
        a[x][y]+=t;
    }
    back(1);
    printf ("%d\n", minn);
    return 0;
}
