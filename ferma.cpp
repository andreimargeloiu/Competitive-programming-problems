# include <fstream>
# include <algorithm>
# define NR 12000
# define inf -999999999
using namespace std;
ifstream f("ferma.in");
ofstream g("ferma.out");
int i,j,n,m,k,maxx, maxi;
int a[10005][1005], x[NR];
int main ()
{
    f>>n>>k;
    for (i=1; i<=n; ++i) f>>x[i];

    //a[i][j] - suma maxima sa iei din primele i elemente j secvente
    for (i=0; i<=n; ++i)
        for (j=0; j<=k+1; ++j)
            a[i][j]=inf;
    a[0][0]=a[0][1]=a[1][0]=0;

    for (j=1; j<=k+1; ++j)
    {
        maxi=inf;
        for (i=1; i<=n; ++i)
        {
            if (i>=j) a[i][j]=x[i] + max(a[i-1][j], maxi);
            maxi=max(maxi, a[i][j-1]);
        }

        if (j==k) maxx=a[n][k];
        if (j==k+1) maxx=max (maxx, a[n][k+1]);
    }
    if (maxx<0) g<<"0\n";
           else g<<maxx<<"\n";

    return 0;
}
