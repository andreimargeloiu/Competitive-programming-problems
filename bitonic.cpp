# include <fstream>
# define NR 1005
using namespace std;
ifstream f("bitonic.in");
ofstream g("bitonic.out");
int i,j,n,m,x,y,nr1,nr2,t,teste,maxx;
int a[NR];
int main ()
{
    f>>teste;

    for (t=1; t<=teste; ++t)
    {
        f>>n; maxx=1;
        for (i=1; i<=n; ++i)
            f>>a[i];

        for (i=1; i<=n; ++i)
        {
            nr1=0; nr2=0;
            // > > 0 < <
            for (j=i-1; j>=1; --j) if (a[j]>a[j+1]) ++nr1;
            for (j=i+1; j<=n; ++j) if (a[j]>a[j-1]) ++nr2;
            maxx=max(maxx, nr1+nr2+1);

            nr1=0; nr2=0;
            // < < 0 > >
            for (j=i-1; j>=1; --j) if (a[j]<a[j+1]) ++nr1;
            for (j=i+1; j<=n; ++j) if (a[j]<a[j-1]) ++nr2;
            maxx=max(maxx, nr1+nr2+1);
        }
        g<<maxx<<"\n";
    }




    return 0;
}
