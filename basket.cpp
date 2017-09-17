# include <cstdio>
# include <algorithm>
using namespace std;
long long a[304][304];
int i, j, m, n, p, t;
void generare(int p)
{
    int i, j;
    a[1][1]=1;
    for(i=2; i<=300; ++i)
        for(j=1; j<=i; ++j)
        a[i][j]=(j*a[i-1][j]+(i-j+1)*a[i-1][j-1])%p;
}
int main()
{
    freopen ("basket.in", "r", stdin);
    freopen ("basket.out", "w", stdout);
    scanf("%d%d", &t, &p);
    generare(p);
    for(int k=1; k<=t; ++k)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", a[n][m+1]);
    }
    return 0;
}
