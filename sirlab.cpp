# include <fstream>
# include <cstring>
# include <algorithm>
# include <vector>
# define NR 1000
using namespace std;
ifstream f("sir.in");
ofstream g("sir.out");
struct elem
{
    int ci, cs;
}var[1505];
vector <int> v[NR];
int i,j,n,m,ci,cs,VV;
long long suma[NR];
char s[NR];
int main ()
{
    f.getline(s+1, NR);
    n=strlen(s+1);
    for (i=1; i<=n; ++i)
    {
        //simple
        ci=i-1; cs=i+1;
        while (1<=ci && cs<=n && s[ci]==s[cs])
        {
            var[++VV].ci=ci; var[VV].cs=cs;
            --ci; ++cs;
        }

        //duble
        if (s[i]==s[i+1])
        {
            ci=i-1; cs=i+2;
            while (1<=ci && cs<=n && s[ci]==s[cs])
            {
                var[++VV].ci=ci; var[VV].cs=cs;
                --ci; ++cs;
            }
        }
    }
    for (i=1; i<=VV; ++i)
        v[var[i].cs].push_back(var[i].ci);

    suma[0]=1; suma[1]=1;
    for (i=2; i<=n; ++i)
    {
        suma[i]=suma[i-1];
        if (s[i]==s[i-1]) suma[i]+=suma[i-2];

        for (j=0; j<v[i].size(); ++j)
            suma[i]+=suma[v[i][j]-1];
    }
    g<<suma[n]<<"\n";

    return 0;
}
