# include <fstream>
# include <algorithm>
# define MOD 10000
using namespace std;
ifstream f("diamant.in");
ofstream g("diamant.out");
int i,j,n,m,nr,VV,P,S,maxx;
int A[100000], B[100000], a[5000];
int main ()
{
    f>>n>>m>>S;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            a[++VV]=i*j, maxx+=i*j;

    if (S<-maxx || maxx<S)
    {
        g<<"0\n";
        return 0;
    }

    P=maxx*2;
    for (i=1; i<=VV; ++i)
    {
        //adaug nr pozitiv
        nr=a[i]; B[maxx+nr]+=1;
        for (j=0; j<=P; ++j)
            if (A[j]) B[j+nr]+=A[j];

        //adaug nr negativ
        nr=-a[i]; B[maxx+nr]+=1;
        for (j=0; j<=P; ++j)
            if (A[j]) B[j+nr]+=A[j];

        for (j=0; j<=P; ++j)
        {
            A[j]+=B[j];
            if (A[j]>MOD) A[j]%=MOD;
            B[j]=0;
        }
    }
    ++A[maxx]; A[maxx]%=MOD;
    g<<A[maxx+S];
    return 0;
}
