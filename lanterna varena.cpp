# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("lanterna.in");
ofstream g("lanterna.out");
int a[100005];
int main ()
{
    int i,n;
    f>>n;
    for (i=1; i<=n; ++i)
        f>>a[i];
    sort (a+1, a+n+1);

    long long s=0;
    while (n>3)
    {
        s+=min(2*a[2]+a[n]+a[1], 2*a[1]+a[n-1]+a[n]);
        n=n-2;
    }
    if (n==3) s+=a[1]+a[2]+a[3];
    else s+=a[2];
    g<<s<<"\n";

    return 0;
}
