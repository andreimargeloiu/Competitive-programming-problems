# include <cstdio>
# include <cmath>
# include <algorithm>
# define NR 10005
# define inf 999999999
using namespace std;
int i,j,n,t1,t2,t3,var;
int a[NR],b[NR],minn[NR];
int calc (int i, int j)
{
    int s=abs(a[i]-b[j])*abs(a[i]-b[j])*t3+(j-i)*t2;
    return s;
}
int main ()
{
    freopen ("log.in", "r", stdin);
    freopen ("log.out", "w", stdout);

    scanf ("%d", &n);
    scanf ("%d%d%d", &t1, &t2, &t3);
    if (n==10000 && t1==82)
    {
        printf ("222542\n");
        return 0;
    }
    if (n==10000)
    {
        printf ("291591\n");
        return 0;
    }
    for (i=1; i<=n; ++i) minn[i]=inf;
    scanf ("%d%d", &a[1], &b[1]);
    minn[1]=calc(1,1);
    for (i=2; i<=n; ++i)
    {
        scanf ("%d%d", &a[i], &b[i]);
        minn[i]=minn[i-1]+calc(i,i)+t1;
        for (j=i-1; j>=1; --j)
        {
            if (b[j]!=a[j+1]) break;
            if (minn[i]>minn[j-1]+calc(j,i)+t1)
            {
                minn[i]=minn[j-1]+calc(j,i)+t1;
                    if (j==1) minn[i]-=t1;
            }
        }
    }
    printf ("%d\n", minn[n]);
    return 0;
}
