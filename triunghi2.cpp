# include <cstdio>
# include <algorithm>
# define N_Max 1005
using namespace std;
int i,j,n,nr,x,var,I,J,S;
int a[N_Max][N_Max],V[N_Max][N_Max],O[N_Max][N_Max],minn[N_Max][N_Max];
int main ()
{
    freopen ("triunghi2.in", "r", stdin);
    freopen ("triunghi2.out", "w", stdout);
    scanf ("%d", &n); nr=n*(n+1)/2;
    I=n; J=1; var=1;
    for (i=1; i<=nr; ++i)
    {
        scanf ("%d", &x);
        a[I][J]=x;
        --I; --J;
        if (J==0) ++var,I=n,J=var;
    }
    //pe coloane
    for (j=1; j<=n; ++j)
    {
        nr=0; S=0; var=0;
        for (i=j+1; i<=n; ++i)
        {
            ++nr;
            S+=a[i][j]+a[i][j+1];
            V[i][j]=S*nr + a[i][j]+a[i-1][j]+var;
            var+=a[i][j]+a[i-1][j];
        }
    }
    //pe linii
    for (i=1; i<=n; ++i)
    {
        nr=0; S=0; var=0;
        for (j=i-1; j>=1; --j)
        {
            ++nr;
            S+=a[i][j]+a[i-1][j];
            O[i][j]=S*nr + a[i][j]+a[i][j+1]+var;
            var+=a[i][j]+a[i][j+1];
        }
    }

    //prima banda
    I=2; J=1;
    while (I<=n)
    {
        minn[I][J]=2*a[I][J]+a[I-1][J]+a[I][J+1];
        ++I; ++J;
    }
    //restul
    for (I=3; I<=n; ++I)
    {
        i=I; j=1;
        while (i<=n)
        {
            minn[i][j]=min(minn[i-1][j]+O[i][j],minn[i][j+1]+V[i][j]);
            ++i; ++j;
        }
    }

    printf ("%d\n", minn[n][1]);

    return 0;
}
