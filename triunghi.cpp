# include <fstream>
# include <algorithm>
# define NR 1000005
using namespace std;
ifstream f("triunghi.in");
ofstream g("triunghi.out");
int i,j,n,m,SUMA,S,I;
int a[100][100], ant[NR], suma[100];
void curata ()
{
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=i; ++j)
            a[i][j]=0;
}
int numara ()
{
    int S=0;
    for (int i=n-1; i>=1; --i)
        for (int j=1; j<=i; ++j)
        {
            a[i][j]=a[i+1][j] + a[i+1][j+1];
            S+=a[i][j];
        }
    return S;
}
void preproc ()
{
    for (int i=1; i<=n; ++i)
    {
        curata ();
        a[n][i]=1;
        S=numara () + 1;
        SUMA=SUMA-S;

        suma[i]=S;
    }
}
void afisare ()
{
    int i,j;
    curata ();
    for (i=1; i<=n; ++i)
        a[n][i]=1;

    I=SUMA;
    while (I!=0)
    {
        ++a[n][ant[I]];
        I=I-suma[ant[I]];
    }

    for (int i=n-1; i>=1; --i)
        for (int j=1; j<=i; ++j)
            a[i][j]=a[i+1][j] + a[i+1][j+1];

    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=i; ++j)
            g<<a[i][j]<<" ";
        g<<"\n";
    }
}
int main ()
{
    f>>n>>SUMA;

    preproc ();

    ant[0]=1;
    for (i=1; i<=n; ++i) //fiecare element
    {
        for (j=suma[i]; j<=SUMA; ++j)
            if (ant[j-suma[i]]) ant[j]=i;

        if (ant[SUMA])
        {
            afisare ();
            return 0;
        }
    }

    return 0;
}
