# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("oo.in");
ofstream g("oo.out");
int i,j,n,m,maxx;
int sum[NR], a[NR];
void numara (int ci, int cs)
{
    memset (sum, 0, sizeof(sum));
    for (int i=ci+1; i<=cs; ++i)
    {
        sum[i]=max(sum[i-1], sum[i-3]+a[i-1]+a[i]);
    }
    maxx=max(maxx, sum[cs]);
}
int main ()
{
    f>>n;
    if (n==2)
    {
        g<<"0\n";
        return 0;
    }

    for (i=1; i<=n; ++i)
        f>>a[i];
    a[n+1]=a[1];

    numara (1, n-1);
    numara (2, n);
    numara (3, n+1);

    g<<maxx<<"\n";

    return 0;
}
