# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("csir.in");
ofstream g("csir.out");
int i,j,n,m,t,T;
int a[NR];
char s[NR];
int verifica (int n) {
    int i,ok=1;
    //dublez
    for (i=1; i<=n; ++i)
        a[i+n]=a[i];

    //daca are toate elementele identice e bun
    for (i=2; i<=n+1; ++i)
        if (a[i-1]!=a[i]) ok=0;
    if (ok) return 1;

    ok=0;
    //caut permutarea 'frumoasa'
    for (i=1; i<=n && !ok; ++i)
        if (a[i]==1 && a[i+n-1]==2) { // incepe cu A si se termina cu B
            ok=1;
            for (int j=1; j<=n; ++j)
                a[j]=a[i+j-1];
        }
    if (! ok) return 0;

    int minn=9999999, maxx=0;
    //il compactam
    for (i=1; i<=n; i+=0) {
        int nrA=0;
        while (a[i]==1)
            ++nrA, ++i;
        ++i; //trec de B

        minn=min(minn, nrA);
        maxx=max(maxx, nrA);
    }
    if (minn+1<maxx) return 0;

    int VV=0;
    //il condensam ca sa trecem la etapa urmatoare
    for (i=1; i<=n; i+=0) {
        int nrA=0;
        while (a[i]==1)
            ++nrA, ++i;

        if (nrA==minn) a[++VV]=1;
                  else a[++VV]=2;

        ++i; //trec de B
    }
    return verifica (VV);
}
int main ()
{
    f>>T; f.get();
    for (int t=1; t<=T; ++t) {
        f.getline (s+1, NR); n=strlen(s+1);
        for (i=1; i<=n; ++i)
            if (s[i]=='A') a[i]=1;
                      else a[i]=2;

        g<<verifica (n)<<"\n";
    }

    return 0;
}
