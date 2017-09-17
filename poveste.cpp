# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1005
using namespace std;
ifstream f("poveste.in");
ofstream g("poveste.out");
int i,j,n,m,x,t,o,maxx,l,k;
int a[NR][NR], pi[NR];
char s[NR];
int main ()
{
    f>>t;
    for (o=1; o<=t; ++o)
    {
        f>>n>>m; f.get();
        for (i=1; i<=n; ++i)
        {
            f.getline (s+1, NR);
            for (j=1; j<=m; ++j)
                a[j][i]=s[j]-'0';

        }
        swap (n, m); maxx=m;

        for (i=1; i<n; ++i) // prima linie
        {
            //prefix
            k=0; memset(pi, 0, sizeof(pi));
            for (l=2; l<=m; ++l)
            {
                while (k>0 && a[i][k+1]!=a[i][l])
                    k=pi[k];

                if (a[i][k+1]==a[i][l]) ++k;

                pi[l]=k;
            }

            for (j=i+1; j<=n; ++j) // a doua linie
            {
                k=0;
                for (l=1; l<=m; ++l)
                {
                    while (k>0 && a[i][k+1]!=a[j][l])
                        k=pi[k];

                    if (a[i][k+1]==a[j][l]) ++k;

                    maxx=max(maxx, (j-i+1)*k);
                }
            }
        }
        g<<maxx<<"\n";
    }
    return 0;
}
