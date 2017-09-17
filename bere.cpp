# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("br.in");
ofstream g("br.out");
int a[50000],s[50000];
int i,j,n,m,ind,bani,*x,poz,VV;
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
    {
        f>>a[i];
        a[n+i]=a[i];
    }
    for (i=1; i<=2*n; ++i)
        s[i]=s[i-1]+a[i];

    for (i=1; i<=m; ++i)
    {
        f>>ind>>bani;
        bani+=s[ind-1];
        x=upper_bound(s+1,s+2*n+1,bani);
        poz=x-s-1;
        VV=poz-ind+1;
        if (VV>n) g<<n<<"\n";
           else if (VV>0) g<<VV<<"\n";
               else g<<"0\n";
    }
    return 0;
}
