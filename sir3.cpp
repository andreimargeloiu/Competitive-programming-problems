# include <cstdio>
using namespace std;
int i,j,n,m,suma,target,VV1,VV2;
int put[100],cost[905][35],st[100],sol1[50][100], sol2[50][100];
void first (int k)
{
    int i;
    if (k==n+1)
    {
        if (suma==target && VV1<40)
        {
            ++VV1;
            for (i=1; i<=n; ++i)
                sol1[VV1][i]=st[i];
        }
    }
    else{
            for (i=st[k-1]; suma+cost[i][n-k+1]<=target && VV1<40; ++i)
            {
                if (suma+i>=put[k])
                {
                    suma+=i; st[k]=i;
                    first (k+1);
                    suma-=i; st[k]=0;
                }
                else i=put[k]-suma-1;
            }
        }
}
void second (int k)
{
    int i;
    if (k==n+1)
    {
        if (suma==target && VV2<20)
        {
            ++VV2;
            for (i=1; i<=n; ++i)
                sol2[VV2][i]=st[i];
        }
    }
    else
    {
        for (i=35; i>=1 && i>=st[k-1] && VV2<20; --i)
        {
            if (suma+cost[i][n-k+1]<=target)
            {
                if (suma+i>=put[k])
                {
                    suma+=i; st[k]=i;
                    second (k+1);
                    suma-=i; st[k]=0;
                }
                else break;
            }
        }
    }
}
int main ()
{
    freopen ("sir3.in", "r", stdin);
    freopen ("sir3.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        put[i]=i*i;
    target=n*n;
    for (i=1; i<=target; ++i)
    {
        for (j=1; j<=n; ++j)
            cost[i][j]=i*j;
    }

    VV1=0;
    first(1);
    if (VV1<40)
    {
        for (i=1; i<=VV1; ++i)
        {
            for (j=1; j<=n; ++j)
                printf ("%d ", sol1[i][j]);
            printf ("\n");
        }
    }
    else if (VV1==40)
    {
        for (i=1; i<=20; ++i)
        {
            for (j=1; j<=n; ++j)
                printf ("%d ", sol1[i][j]);
            printf ("\n");
        }
    }
    VV2=0; suma=0;
    if (VV1==40)
    {
        second (1);
        for (i=VV2; i>=1; --i)
        {
            for (j=1; j<=n; ++j)
                printf ("%d ", sol2[i][j]);
            printf ("\n");
        }
    }
    return 0;
}
