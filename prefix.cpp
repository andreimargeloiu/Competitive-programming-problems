# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("prefix.in");
ofstream g("prefix.out");
int i,j,o,VV,k,t,la,ok;
int pi[NR];
char a[NR];
int main ()
{
    f>>t; f.get();
    for (o=1; o<=t; ++o)
    {
        f.getline(a+1, NR); la=strlen(a+1);
        k=0;
        for (i=2; i<=la; ++i)
        {
            while (k>0 && a[k+1]!=a[i])
                k=pi[k];

            if (a[k+1]==a[i]) ++k;
            pi[i]=k;
        }
        ok=0;
        for (i=la; i>=1; --i)
            if (pi[i]!=0 && i%(i-pi[i])==0) {g<<i<<"\n"; ok=1; break;}
        if (!ok) g<<"0\n";
    }

    return 0;
}
