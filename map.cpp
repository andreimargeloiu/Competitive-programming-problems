# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 2005
using namespace std;
ifstream f("map.in");
ofstream g("map.out");
int i,j,n,m;
int ap[NR],pi[NR],AP[NR];
char s[NR];
void KMP ()
{
    int k=0,VV;
    memset (pi, 0, sizeof(pi));
    memset (ap, 0, sizeof(ap));
    //prefixul
    for (int i=2; i<=m; ++i) {
        while (k>0 && s[k+1]!=s[i])
            k=pi[k];

        if (s[k+1]==s[i]) ++k;
        pi[i]=k;
    }

    VV=pi[m];
    while (VV) {
        if (VV>=m/2+1) ++ap[VV];
                  else ++ap[m-VV+1];
        VV=pi[VV];
    }
    for (int i=1; i<=m; ++i)
        if (ap[i]) ++AP[i];
}
int main ()
{
    f>>n>>m; f.get();
    for (i=1; i<=n; ++i) {
        f.getline(s+1, NR);
        KMP ();
    }

    for (i=m/2+1; i<=m; ++i)
        if (AP[i]==n) {
            g<<i<<"\n";
            return 0;
        }
    g<<m<<"\n";


    return 0;
}
