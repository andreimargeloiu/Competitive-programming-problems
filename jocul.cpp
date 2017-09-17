# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("jocul.in");
ofstream g("jocul.out");
int i,j,n,suma,S,maxx1,maxx2;
int a[1005],ap[50005];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        S+=a[i];
    }
    suma=S;
    S=(S+1)/2; ap[0]=1;
    for (i=1; i<=n; ++i)
    {
        for (j=S-a[i]; j>=0; --j)
            if (ap[j]) ap[j+a[i]]=1;
    }
    for (i=1; i<=S; ++i)
        if (ap[i] && i>maxx1) maxx1=i,maxx2=suma-i;
    if (maxx1>maxx2) swap(maxx1,maxx2);
    g<<maxx1<<" "<<maxx2<<"\n";
    return 0;
}
