# include <fstream>
# include <algorithm>
# define mod 666013
# define NR 1005
using namespace std;
ifstream f("xnumere.in");
ofstream g("xnumere.out");
int i,j,m,X,K,I;
int c[NR][NR], d[NR];
long long n;
void combinari ()
{
    c[1][0]=c[1][1]=1;
    for (int i=2; i<=K; ++i)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1; j<i; ++j)
        {
            c[i][j]=c[i-1][j-1] + c[i-1][j];
            if (c[i][j]>=mod) c[i][j]-=mod;
        }
    }
}
int put (int a, long long n)
{
    int rez=1;
    while (n>0)
    {
        if (n%2==1)
        {
            rez=1LL*rez*a%mod;
            --n;
        }
        else {
                 a=1LL*a*a%mod;
                 n=n/2;
             }
    }
    return rez;
}
int main ()
{
    f>>K>>X>>n;

    // d[i] - numarul de moduri de a face siruri din n cifre
    //        folosind primele i cifre distincte

    combinari ();

    d[1]=1;
    for (i=2; i<=X; ++i)
    {
        I=put(i, n);

        int S=0;
        for (j=1; j<i; ++j)
        {
            S=(S + 1LL*d[j]*c[i][j])%mod;
        }

        d[i]=I-S;
        if (d[i]<0) d[i]+=mod;
    }

    g<<(1LL*d[X]*c[K][X])%mod<<"\n";


    return 0;
}
