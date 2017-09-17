# include <cstdio>
# include <algorithm>
# define NR 500005
using namespace std;
int i,j,n,m,VV,var;
int a[NR];
bool ap[NR];
long long S[NR], S1, S2;
long long DFS (int k)
{
    long long suma=0;

    while (! ap[k])
    {
        suma+=a[k];
        ap[k]=1;
        k=a[k];
    }

    return suma;
}
int main ()
{
    freopen ("monopoly.in", "r", stdin);
    freopen ("monopoly.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
        scanf ("%d", &a[i]);

    for (i=1; i<=n; ++i)
        if (! ap[i]) S[++VV]=DFS (i);

    sort (S+1, S+VV+1);

    for (i=VV; i>=1; --i)
    {
        ++var;
        if (var%2==1) S1+=S[i];
                 else S2+=S[i];
    }
    printf ("%lld\n%lld\n", S1, S2);

    return 0;
}
