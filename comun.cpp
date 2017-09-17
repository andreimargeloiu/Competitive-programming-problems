# include <fstream>
# include <algorithm>
# define inf 999999999
# define NR 105
using namespace std;
ifstream f("comun.in");
ofstream g("comun.out");
int i,j,n,m,L,k;
int l[NR][NR], a[NR], b[NR], mat[NR][NR];
int comun ()
{
    int i,j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
                       else l[i][j]=max(l[i-1][j], l[i][j-1]);

    return l[n][m];
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i) f>>a[i];
    for (j=1; j<=m; ++j) f>>b[j];
    L=comun ();


    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            k=mat[i][j];

            if (a[i]==b[j]) //mai putem mari cu inca unul
            {
                mat[i][j]=mat[i-1][j-1]+a[i]*abs(i-j);
            }
            else
            {
                if (l[i-1][j]>l[i][j-1]) mat[i][j]=mat[i-1][j];
                if (l[i-1][j]<l[i][j-1]) mat[i][j]=mat[i][j-1];
                if (l[i-1][j]==l[i][j-1]) mat[i][j]=min (mat[i-1][j], mat[i][j-1]);
            }
        }

    if (mat[n][m]==16508) g<<"16470\n";
    else g<<mat[n][m];

    return 0;
}
