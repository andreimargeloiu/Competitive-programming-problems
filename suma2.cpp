# include <fstream>
# include <cstring>
# define NR 2005
# include <algorithm>
using namespace std;
ifstream f("suma2.in");
ofstream g("suma2.out");
int i,j,n,m,VV;
int a[NR],b[NR],v[NR];
char s[NR];
int main ()
{
    f>>n; f.get();
    f.getline(s+1, 2005); m=strlen(s+1);
    for (i=1; i<=m; ++i)
        if ('0'<=s[i] && s[i]<='9') v[++VV]=s[i]-'0';

    // a[i][j] - maximul pe care il pot forma din i cuvinte de lungime totala j
    for (i=1; i<=min(n,3); ++i)
        a[i]=a[i-1]*10+v[i];

    for (i=2; i<=n; ++i)
    {
        for (j=1; j<=VV; ++j)
        {
            //o cifra
            if (a[j-1] && v[j])
                b[j]=max(b[j], a[j-1]+v[j]);
            //doua cifre
            if (a[j-2] && v[j-1])
                b[j]=max(b[j], a[j-2]+(v[j-1]*10+v[j]));
            //trei cifre
            if (a[j-3] && v[j-2])
                b[j]=max(b[j], a[j-3]+(v[j-2]*100+v[j-1]*10+v[j]));
        }
        for (j=1; j<=VV; ++j)
            a[j]=b[j], b[j]=0;
    }

    g<<a[VV]<<"\n";

    return 0;
}
