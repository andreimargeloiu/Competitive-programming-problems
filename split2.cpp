# include <algorithm>
# include <fstream>
# define NR 1005
# define inf 999999999
using namespace std;
ifstream f("split2.in");
ofstream g("split2.out");
int
void init (int n, int m)
{
    int i,j;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            cost[i][j]=inf;
}
int main ()
{
    f>>t;
    //cost[i][j]-costul minim sa impartim primele i numere in j subsecvente
    for (o=1; o<=t; ++o)
    {
        f>>n>>m;
        init (n,m);
        for (i=1; i<=n; ++i)
            { f>>a[i]; S[i]=S[i-1]+a[i]; }

        for (j=1; j<=m; ++j)
            for (i=2; i<=n; i=i+2)
            {

            }
    }



    return 0;
}
