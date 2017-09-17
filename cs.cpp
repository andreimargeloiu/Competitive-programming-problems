# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("cs.in");
ofstream g("cs.out");
int i,j,n,a[100005];
void inmultire (int k)
{
    int i,t=0;
    for (i=1; i<=a[0]; ++i)
    {
        t=t+a[i]*k;
        a[i]=t%10;
        t=t/10;
    }

    while (t) a[++a[0]]=t%10, t=t/10;
}
int main ()
{
    f>>n;
    a[0]=a[1]=1;
    for (i=1; i<=n; ++i)
        inmultire (n);
    for (i=1; i<=n-1; ++i)
        inmultire (2);

    for (i=a[0]; i>=1; --i)
        g<<a[i];
    g<<"\n";


    return 0;
}
