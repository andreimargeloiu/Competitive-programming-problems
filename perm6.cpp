# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1100
# define N 50
# define base 1000000
using namespace std;
ifstream f("perm6.in");
ofstream g("perm6.out");
int i,j,n,m,K,poz;
int a[N][NR][50], var[10]; // - numarul de permutari din i elemente cu j inversiuni
void aduna (int a[], int b[])
{
    int t=0;
    a[0]=max (a[0], b[0]);
    for (int i=1; i<=a[0]; ++i)
    {
        a[i]=t+a[i]+b[i];
        if (a[i]>=base) t=1, a[i]-=base;
                   else t=0;
    }
    if (t) a[++a[0]]=t;
}
void afisare (int k)
{
    memset (var, 0, sizeof(var));
    int i, VV=0;
    while (k>0) var[++VV]=k%10, k=k/10;

    for (i=6; i>=1; --i)
        g<<var[i];
}
int main ()
{
    f>>n>>K;

    a[0][0][0]=a[0][0][1]=1;
    for (i=1; i<=n; ++i)
    {
        for (poz=i; poz>=1; --poz)
        {
            for (j=0; j<=K - (i-poz); ++j)
                aduna (a[i][j + (i-poz)], a[i-1][j]);
        }
    }
    g<<a[n][K][a[n][K][0]]; --a[n][K][0];
    for (i=a[n][K][0]; i>=1; --i)
        afisare (a[n][K][i]);

    g<<"\n";

    return 0;
}
