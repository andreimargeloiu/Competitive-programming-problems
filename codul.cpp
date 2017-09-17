# include <fstream>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("codul.in");
ofstream g("codul.out");
int i,j,n,m,VV,I,J,maxx,var,poz,still,ok;
int d[205][205],Amax[205];
char a[1005], b[1005];
int main ()
{
    f.getline(a+1, 1005); n=strlen(a+1);
    f.getline(b+1, 1005); m=strlen(b+1);

    for (i=n; i>=1; --i)
        for (j=m; j>=1; --j)
        {
            if (a[i]==b[j]) d[i][j]=d[i+1][j+1]+1;
                else d[i][j]=max(d[i+1][j], d[i][j+1]);
            Amax[i]=max(Amax[i],d[i][j]);
        }
    poz=1; still=Amax[1]; i=1;
    while (i<=n+1)
    {
        ok=1;
        if (Amax[i]<still) //daca scade
        {
            g<<maxx; maxx=0; --still;
            i=I+1; var=J+1; ok=0;
        }
        if (i==n+1 || still==0) break;

        for (j=var; j<=m; ++j)
            if (d[i][j]>=still && a[i]==b[j])
            {
                if (b[j]-'0'>maxx) maxx=b[j]-'0', I=i, J=j;
            }
        if (ok) ++i;
    }
    g<<"\n";

    return 0;
}
