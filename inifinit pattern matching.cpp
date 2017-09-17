# include <fstream>
# include <algorithm>
# include <cstring>
# include <bitset>
# define inf 999999999
using namespace std;
ifstream f("infinitepatternmatching.in");
ofstream g("infinitepatternmatching.out");
int i,j,n,o,P,X,VV,ok;
int B[100], var[100];
long long nr,NR,Q;
char b[100];
bitset <15000005> p;
long long numara (int K) {
    if (K==0) return 0;
    else return (1<<(K-1));
}
long long pozitie (int nr) {
    long long rez=0, VV=-1;
    while (nr>0) {
        var[++VV]=nr%2;
        nr/=2;
    }

    for (int i=1; i<=VV; ++i)
        rez=rez + numara(i)*i;

    for (int i=VV; i>=0; --i) {
        if (var[i]==1) rez=rez + numara(i)*(VV+1);
    }
    return rez+1;
}
int main ()
{
    f.getline (b+1, 100); n=strlen(b+1);
    for (i=1; i<=n; ++i) {
        B[i]=(int)(b[i]-'0');
        nr=nr*2 + B[i];
    }
    if (B[1]==0) Q=(1<<(n)), nr+=Q;
    for (i=1; i<=(1<<19); ++i) {
        X=i; VV=0;
        while (X) {
            var[++VV]=X%2;
            X/=2;
        }
        for (j=VV; j>=1; --j)
            p[++P]=var[j];
    }

    for (i=1; i<n; ++i)
        NR=NR*2 + p[i];

    for (i=n; i<=P; ++i) {
        if (i==42) {
            ok=0;
        }
        NR=NR*2 + p[i];

        if (NR + Q==nr) {
            g<<i<<"\n";
            return 0;
        }

        NR=NR-(1<<(n-1))*p[i-n+1];
    }
    g<<pozitie (nr) +n-1;

    return 0;
}
