# include <fstream>
# include <cstring>
# include <algorithm>
# include <bitset>
using namespace std;
ifstream f("binar.in");
ofstream g("binar.out");
int i,j,n,m,VV;
bitset <2005> a[2005];
int var[2005];
char s[2005];
void divide (int ci, int cs, int lvl)
{
    if (lvl==n+1)
    {
        if (ci==cs) return;
        else sort (var+ci, var+cs);
    }
    else
    {
        if (ci==cs) return;
        short cif[2005],z=0,u=2002,i,z1=0,u1=2002;
        for (i=ci; i<=cs; ++i)
        {
            if (a[lvl][var[i]]==0) cif[++z]=var[i];
                else cif[--u]=var[i];
        }
        for (i=ci; i<=ci+z-1; ++i)
            var[i]=cif[++z1];
        for (i=ci+z; i<=cs; ++i)
            var[i]=cif[--u1];

        if (z) divide (ci,ci+z-1, lvl+1);
        if (u1!=2002) divide (ci+z, cs, lvl+1);
    }
}
int main ()
{
    f>>n>>m; f.get();
    for (i=1; i<=n; ++i)
    {
        a[0][i]=i;
        f.getline(s+1, 2005);
        for (j=1; j<=m; ++j)
            a[i][j]=s[j]-'0';
    }
    for (i=1; i<=m; ++i)
        var[i]=i;
    divide (1,m,1);

    for (i=1; i<=m; ++i)
        g<<var[i]<<" ";
    g<<"\n";
    return 0;
}
