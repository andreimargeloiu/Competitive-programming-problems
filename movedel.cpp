# include <fstream>
# include <cstring>
# include <algorithm>
# include <bitset>
# define NR 50005
using namespace std;
ifstream f("movedel.in");
ofstream g("movedel.out");
int i,j,n,m,k,ok,solutie,VV,maxx,MINUS;
int prim[NR], M[NR], A[150], B[150];
bitset <2*NR+5> ap;
char a[NR], b[NR], var[NR];
void ciur ()
{
    prim[1]=2; k=1;
    for (int i=3; i<=2*NR; i+=2)
        if (! ap[i])
        {
            prim[++k]=i;
            for (j=3; i*j<=2*NR; j+=2)
                ap[i*j]=1;
        }
}
void roteste ()
{
    k=prim[ok]%n; VV=0;
    for (i=k+1; i<=n; ++i)
        var[++VV]=a[i];
    for (i=1; i<=k; ++i)
        var[++VV]=a[i];
    for (i=1; i<=n; ++i)
        a[i]=var[i];

    k=(prim[ok]+1)%n; VV=0;
    for (i=n-k+1; i<=n; ++i)
        var[++VV]=b[i];
    for (i=1; i<=n-k; ++i)
        var[++VV]=b[i];
    for (i=1; i<=n; ++i)
        b[i]=var[i];
}
bool verifica ()
{
    memset (A, 0, sizeof(A));
    memset (B, 0, sizeof(B));
    for (i=1; i<=n; ++i)
        A[a[i]]=1;
    for (i=1; i<=n; ++i)
        B[b[i]]=1;

    for (i=1; i<=150; ++i)
        if (A[i]==1 && A[i]==B[i]) return 1;
    return 0;
}
int main ()
{
    ciur ();

    f.getline (a+1, NR); n=strlen(a+1);
    f.getline (b+1, NR);


    ok=1;
    // n - cate elemente am la un moment dat
    while (ok)
    {
        roteste ();
        if (! verifica()) break;

        /*for (i=1; i<=n; ++i)
            g<<a[i];
        g<<" ";
        for (i=1; i<=n; ++i)
            g<<b[i];
        g<<"\n";*/

        VV=0; maxx=0; MINUS=0; i=1;
        while (i<=n)
        {
            if (a[i]==b[i])
            {
                int var=0;
                while (a[i]==b[i] && i<=n)
                    ++i, ++var;
                maxx=max(maxx, var);
            }
            else ++i;
        }
        i=1;
        while (i<=n)
        {
            if (a[i]==b[i])
            {
                int I=i, var=0;
                while (a[I]==b[I] && I<=n)
                    ++I, ++var;
                if (var==maxx) MINUS+=maxx;//daca se elimina
                else { //nu se elimina
                         for (int j=i; j<=I-1; ++j)
                         {
                             ++VV;
                             a[VV]=a[j];
                             b[VV]=b[j];
                         }
                     }
                i=I;
            }
            else
            {
                ++VV;
                a[VV]=a[i];
                b[VV]=b[i];
                ++i;
            }
        }


        for (i=n-MINUS+1; i<=n; ++i)
            a[i]=b[i]=NULL;
        n=n-MINUS;

        ++solutie, ++ok;
        if (n==0) break;
    }

    g<<solutie<<"\n";

    return 0;
}
